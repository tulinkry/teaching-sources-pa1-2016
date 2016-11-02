#include <stdio.h>
#include <assert.h>

/**
 * Program načte ze vstupu datum ve formátu D/M/Y.
 *
 * Program signalizuje jak chybný formát, tak nevalidní datum. Pro validní datum
 * spočítá kolik dní chybí do konce načteného měsíce.
 */


/* deklarace funkce (bez těla) */
int getDaysOfMonth(int month, int year);

/* definice funkce (s tělem) */
int validateDate (int day, int month, int year)
{
	return (day > 0 && month > 0 && month <= 12 && year >= 1500 && day <= getDaysOfMonth(month, year));
}

int readDate (int * day, int * month, int * year)
{
	return ( scanf ( "%d/%d/%d", day, month, year ) == 3 && validateDate(*day, *month, *year));
}

int isLeapYear (int year)
{
	return year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 );
}

int getDaysOfMonth (int month, int year)
{
	switch ( month )
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return 28 + isLeapYear(year);
	}
	return 0;
}

void test ()
{
	assert(isLeapYear(2016));
	assert(isLeapYear(2020));
	assert(isLeapYear(2000));
	assert(!isLeapYear(2015));
}

int main ( void )
{
	int day, month, year;
	
	/* volani assert testu */
	test ();

	if ( ! readDate ( &day, &month, &year ) )
	{
		printf("Nespravny vstup.\n");
		return 1;
	}

	printf ( "Do konce mesice zbyva %d dni.\n", getDaysOfMonth(month, year) - day );

	return 0;
}
