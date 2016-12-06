#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_MAX_LEN 50

typedef int (*compareFunctionType) ( const void *, const void * );


typedef struct {
  int m_day;
  int m_month;
  int m_year;
} TDATE;

typedef struct {
  char m_name[NAME_MAX_LEN];
  char m_surname[NAME_MAX_LEN];
  TDATE m_birthDate;
  double m_avg;
} TSTUDENT;

int readStudent ( TSTUDENT * student )
{
  char c1, c2;
  return scanf ( "%49s %49s %d%c%d%c%d %lf", student->m_name,
                                             student->m_surname,
                                             &student->m_birthDate.m_day,
                                             &c1,
                                             &student->m_birthDate.m_month,
                                             &c2,
                                             &student->m_birthDate.m_year,
                                             &student->m_avg ) == 8 && 
          c1 == '.' && 
          c2 == '.';
}

void printAll( TSTUDENT* students, int len )
{
  int i = 0;
  for ( i = 0; i < len; i ++ )
    printf ( "%s %s %d.%d.%d %f\n", students[i].m_name, 
                                    students[i].m_surname,
                                    students[i].m_birthDate.m_day,
                                    students[i].m_birthDate.m_month,
                                    students[i].m_birthDate.m_year,
                                    students[i].m_avg );

}

int compAvg ( TSTUDENT * a, TSTUDENT * b )
{
  return a->m_avg - b->m_avg;
}

int compareStudentsByFirtName ( const void* a, const void * b )
{  
  TSTUDENT* stA = (TSTUDENT*) a;
  TSTUDENT* stB = (TSTUDENT*) b;
  return strcmp ( stA -> m_name, stB -> m_name );
}

int compareStudentsBySurname ( const void* a, const void * b )
{  
  TSTUDENT* stA = (TSTUDENT*) a;
  TSTUDENT* stB = (TSTUDENT*) b;
  return strcmp ( stA -> m_surname, stB -> m_surname );
}

int compareStudentsByName ( const void* a, const void * b )
{  
    int res;
    res = compareStudentsBySurname ( a, b );
    if ( res != 0 )
    return res;
    return compareStudentsByFirtName ( a, b );
}


int main(void)
{  
    int len = 0;
    int maxLen = 0;
    TSTUDENT * students = NULL;

    while ( 1 )
    {
        if ( maxLen <= len + 1 )
        {
            maxLen = maxLen ? maxLen * 2 : 10;
            if ( ! ( students = ( TSTUDENT * ) realloc ( students, maxLen * sizeof ( TSTUDENT ) ) ) )
            {
                printf ( "Nespravna alokace.\n" );
                return 1;
            }
        }

        if ( ! readStudent ( &students[len] ) )
            break;

        len ++;
    }

    if ( ! feof ( stdin ) )
    {
        printf ( "Nespravny vstup.\n" );
        free ( students );
        return 1;
    }

    printf("-- as read --\n");
    printAll ( students, len );       

    printf("-- by name --\n");
    /**
     * Předáváme ukazatel funkci int compareStudentsByName ( const void* a, const void * b ),
     * který odpovídá prototypu int (*) ( const void *, const void * )
     *
     * Kompilátor s tím tedy nemá problém.
     */
    qsort ( students, len, sizeof ( *students ), compareStudentsByName );
    /**
     * Lze i alternativně
     * qsort ( students, len, sizeof ( TSTUDENT ), compareStudentsByName );
     * Lze, ale je to špatně:
     * qsort ( students, len, sizeof ( int ), compareStudentsByName ); (špatná velikost položky)
     * qsort ( students, len, sizeof ( students ), compareStudentsByName ); (špatná velikost položky)
     */
    printAll ( students, len );  

    printf("-- by avg --\n");
    /**
     * Předáváme ukazatel na funkci int compAvg ( TSTUDENT * a, TSTUDENT * b ),
     * která neodpovídá prototypu int (*) ( const void *, const void * )
     *
     * Kompilátor si stěžuje, ale protože my víme, co děláme, potlačíme warning přetypováním ukazatele na funkci:
     * ( int (*) ( const void *, const void * ) ) compAvg
     * ^ ------ operace přetypování ----------- ^ (podobně jako (int) a )
     *        ^ - říkáme, že jde o ukazatel na funkci (nepřiřadili jsme mu jméno)
     *   ^ - návratová hodnota funkce, na kterou ukazujeme
     *            ^  seznam parametrů funkce  ^
     *
     * Pokud se to někomu zdá hůře čitelné, může si definovat vlastní typ a použít ho:
     * typedef int (*compareFunctionType) ( const void *, const void * );
     * qsort ( students, len, sizeof( *students ), ( compareFunctionType ) compAvg )
     *
     * Takto je to špatně:
     * ( int (*) ( const int *, const int * ) ) (špatné typy parametrů - opět warning)
     * ( TSTUDENT (*) ( const void *, const void * ) ) (špatný návratový typ - opět warning)
     * ( int * ( const void *, const void * ) ) (není ukazatel na funkci - syntax error)
     * 
     */
    qsort ( students, len, sizeof( *students ), ( int (*) ( const void *, const void * ) ) compAvg );
    /**
     * Ukázka s definovaným typem jako ukazatel na funkci
     */
    qsort ( students, len, sizeof( *students ), ( compareFunctionType ) compAvg );
    printAll ( students, len );  

    free ( students );
    return 0;
}
