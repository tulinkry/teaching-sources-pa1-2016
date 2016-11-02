#include <stdio.h>
#include <assert.h>

/**
 * Program načte ze vstupu 4 celá čísla ve formátu:
 * n d/m/y
 * 	d - den
 *  m - měsíc
 *  r - rok
 *  n - číslo dne v týdnu, kterým daný rok začíná (0 - 6 ~ pondělí - neděle)
 *
 * Na výstup zobrazí pro dané datum např.
 * 	patek 20. brezen 2016 (14)
 * 	^
 * 	den v tydnu v textove reprezentaci (pro 20. 3. 2016)
 * 		  ^
 * 		  den v mesici
 * 		  	   ^
 * 		  	   nazev mesice
 * 		  	   		 ^
 * 		  	   		 rok
 * 		  	   		 	    ^
 * 		  	   		 	    poradove cislo tydne pro dane datum
 */

/**
 * Decide if given year is a leap year
 *
 * @param  y year
 * @return   1 if yes; 0 otherwise
 */
int isLeapYear ( int y )
{
	return 0;
}

/**
 * Get number of days in given month including the leap day
 *
 * @param  m month
 * @param  y year
 * @return   number of days
 */
int daysInMonth ( int m, int y )
{
	return 0;
}

/**
 * Decide if the date is valid gregorian date
 * 	- year is greater than 1582
 * 	- month is between 1 and 12
 * 	- day is between 1 and the number of days in that month
 *
 * @param  d day
 * @param  m month
 * @param  y year
 * @return   1 if is valid; 0 otherwise
 */
int isValidDate ( int d, int m, int y )
{
	return 0;
}

/**
 * Read date from stdin
 *
 * @param  d pointer to the memory where day should be stored
 * @param  m pointer to the memory where month should be stored
 * @param  y pointer to the memory where year should be stored
 * @return   0 if error occured or the date is not valid gregorian date; 1 otherwise
 */
int readDate ( int * d, int * m, int * y )
{
	return 0;
}

/**
 * Get textual representation of a day in czech
 * 
 * @param  day day
 * @return     the string representing the day
 */
const char * dayOfTheWeek ( int day )
{
	switch ( day )
	{
		case 0: return "pondeli";
		case 1: return "utery";
		case 2: return "streda";
		case 3: return "ctvrtek";
		case 4: return "patek";
		case 5: return "sobota";
		case 6: return "nedele";
	}
	return NULL;
}

/**
 * Get textual representation of a month in czech
 *
 * @param  month month
 * @return       the string representinh the month
 */
const char * monthOfTheYear ( int month )
{
	return "brezen";
}

/**
 * Count days before the given date from the beginning of the year
 *
 * @param  d day
 * @param  m month
 * @param  y year
 * @return   number of days before the given date
 */
int daysUntil ( int d, int m, int y )
{
	return 0;
}

/**
 * Count weeks for the given date from the beginning of the year
 * @param  d      day
 * @param  m      month
 * @param  y      year
 * @param  offset day of the week of the 1. 1. of the given year (first day of the year)
 * @return        number of weeks for the given date
 */
int weeksUntil ( int d, int m, int y, int offset )
{
	return 0;
}

/**
 * Get day of the week for the given date
 * @param  d      day
 * @param  m      month
 * @param  y      year
 * @param  offset day of the week of the 1. 1. of the given year (first day of the year)
 * @return        the number representing the day of the week (0-6 for monday-sunday)
 */
int dayFromDate ( int d, int m, int y, int offset )
{
	return 0;
}


void tests ( void )
{
	assert ( isValidDate ( 1, 1, 2016 ) );
	assert ( ! isValidDate ( -1, 1, 2016 ) );
	assert ( ! isValidDate ( 0, 1, 2016 ) );
	assert ( ! isValidDate ( 32, 1, 2016 ) );
	assert ( ! isValidDate ( 32, 1, 111 ) );
	assert ( ! isValidDate ( 32, 0, 2016 ) );
	assert ( ! isValidDate ( 32, 13, 2016 ) );
	assert ( isValidDate ( 28, 2, 2016 ) );
	assert ( isValidDate ( 29, 2, 2016 ) );
	assert ( ! isValidDate ( 30, 2, 2016 ) );
	assert ( ! isValidDate ( 29, 2, 2017 ) );
	assert ( ! isValidDate ( 29, 2, 2015 ) );
	assert ( ! isValidDate ( 29, 2, 2100 ) );

	assert ( daysInMonth ( 1, 2016 ) == 31 );
	assert ( daysInMonth ( 3, 2016 ) == 31 );
	assert ( daysInMonth ( 4, 2016 ) == 30 );
	assert ( daysInMonth ( 5, 2016 ) == 31 );
	assert ( daysInMonth ( 6, 2016 ) == 30 );
	assert ( daysInMonth ( 7, 2016 ) == 31 );
	assert ( daysInMonth ( 8, 2016 ) == 31 );
	assert ( daysInMonth ( 9, 2016 ) == 30 );
	assert ( daysInMonth ( 10, 2016 ) == 31 );
	assert ( daysInMonth ( 11, 2016 ) == 30 );
	assert ( daysInMonth ( 12, 2016 ) == 31 );
	assert ( daysInMonth ( 2, 2016 ) == 29 );
	assert ( daysInMonth ( 2, 2015 ) == 28 );
	assert ( daysInMonth ( 2, 2017 ) == 28 );
	assert ( daysInMonth ( 2, 2000 ) == 29 );
	assert ( daysInMonth ( 2, 2100 ) == 28 );
	assert ( daysInMonth ( 2, 2400 ) == 29 );

	assert ( daysUntil ( 1, 1, 2016 ) == 0 );
	assert ( daysUntil ( 2, 1, 2016 ) == 1 );
	assert ( daysUntil ( 3, 1, 2016 ) == 2 );
	assert ( daysUntil ( 4, 1, 2016 ) == 3 );
	assert ( daysUntil ( 5, 1, 2016 ) == 4 );
	assert ( daysUntil ( 6, 1, 2016 ) == 5 );
	assert ( daysUntil ( 7, 1, 2016 ) == 6 );
	assert ( daysUntil ( 8, 1, 2016 ) == 7 );
	assert ( daysUntil ( 9, 1, 2016 ) == 8 );
	assert ( daysUntil ( 10, 1, 2016 ) == 9 );
	assert ( daysUntil ( 11, 1, 2016 ) == 10 );
	assert ( daysUntil ( 30, 12, 2016 ) == 364 );
	assert ( daysUntil ( 31, 12, 2016 ) == 365 );

	assert ( weeksUntil ( 1, 1, 2016, 4 ) == 0 );
	assert ( weeksUntil ( 2, 1, 2016, 4 ) == 0 );
	assert ( weeksUntil ( 3, 1, 2016, 4 ) == 0 );
	assert ( weeksUntil ( 4, 1, 2016, 4 ) == 1 );
	assert ( weeksUntil ( 5, 1, 2016, 4 ) == 1 );
	assert ( weeksUntil ( 6, 1, 2016, 4 ) == 1 );
	assert ( weeksUntil ( 7, 1, 2016, 4 ) == 1 );
	assert ( weeksUntil ( 8, 1, 2016, 4 ) == 1 );
	assert ( weeksUntil ( 9, 1, 2016, 4 ) == 1 );
	assert ( weeksUntil ( 10, 1, 2016, 4 ) == 1 );
	assert ( weeksUntil ( 11, 1, 2016, 4 ) == 2 );
	assert ( weeksUntil ( 12, 1, 2016, 4 ) == 2 );
	assert ( weeksUntil ( 25, 12, 2016, 4 ) == 51 );
	assert ( weeksUntil ( 26, 12, 2016, 4 ) == 52 );

	assert ( dayFromDate ( 1, 1, 2016, 4 ) == 4 );
	assert ( dayFromDate ( 2, 1, 2016, 4 ) == 5 );
	assert ( dayFromDate ( 3, 1, 2016, 4 ) == 6 );
	assert ( dayFromDate ( 4, 1, 2016, 4 ) == 0 );
	assert ( dayFromDate ( 5, 1, 2016, 4 ) == 1 );
	assert ( dayFromDate ( 6, 1, 2016, 4 ) == 2 );
	assert ( dayFromDate ( 11, 1, 2016, 4 ) == 0 );
	assert ( dayFromDate ( 18, 1, 2016, 4 ) == 0 );
	assert ( dayFromDate ( 25, 1, 2016, 4 ) == 0 );
	assert ( dayFromDate ( 1, 2, 2016, 4 ) == 0 );
	assert ( dayFromDate ( 8, 2, 2016, 4 ) == 0 );
	assert ( dayFromDate ( 15, 2, 2016, 4 ) == 0 );
	assert ( dayFromDate ( 22, 2, 2016, 4 ) == 0 );
}

int main ( void )
{
	int startingDay, y, m, d;

	tests ();

	if ( ! ( scanf ( "%d", &startingDay ) == 1 && 
			 startingDay >= 0 && 
			 startingDay <= 6 && 
			 readDate ( &d, &m, &y ) ) )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}

	printf ( "%s %d. %s %d (%d)\n", 
		dayOfTheWeek ( dayFromDate ( d, m, y, startingDay ) ), 
		d, 
		monthOfTheYear ( m ), 
		y,
		weeksUntil ( d, m, y, startingDay ) );


	return 0;
}
