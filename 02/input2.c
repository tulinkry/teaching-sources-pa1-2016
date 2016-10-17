#include <stdio.h>
/* #include <math.h> - pro fabs, kompilujeme s přepínačem -lm */

/**
 * Program na základní vstup a výstup. Načte dvě celá čísla a vypíše je.
 */

int main(void)
{
    int a;
    int b;

    if ( ! ( scanf( "%d %d", &a, &b ) == 2 && a < b ) )
    {
            printf ( "Nespravny vstup.\n" );
            return 1;
    }


    printf ( "a = %d\nb = %d\n", a, b );

    /*

        if ( fabs ( 4.7 - 4.7f ) / 4.7 < 1e-8 )
        {
                printf ( "Rozdil je nula\n" );
        }
        else
        {
                printf ( "Rozdil neni nula\n" );
        }

    */

    return 0;
}
