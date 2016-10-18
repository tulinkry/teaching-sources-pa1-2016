#include <stdio.h>

/**
 * Program načte ze vstupu datum ve formátu D/M/Y.
 *
 * Program signalizuje jak chybný formát, tak nevalidní datum. Pro validní datum
 * spočítá kolik dní chybí do konce načteného měsíce.
 */

int main ( void )
{
	int day, month, year, daysInMonth;

	if ( ! ( scanf ( "%d/%d/%d", &day, &month, &year ) == 3 && day > 0 && month > 0 && month <= 12 && year >= 1500 ) )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}

	switch ( month )
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			daysInMonth = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			daysInMonth = 30;
			break;
		case 2:
			daysInMonth = 28;
			if ( year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0 ) )
				daysInMonth ++;
			break;
	}

	if ( day > daysInMonth )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}

	printf ( "Do konce mesice zbyva %d dni.\n", daysInMonth - day );

	return 0;
}
