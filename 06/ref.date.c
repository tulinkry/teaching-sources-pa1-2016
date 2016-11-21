#include <stdio.h>
#include <assert.h>

int isLeapYear ( int y )
{
	return ( y % 4 == 0 && ( y % 100 != 0 || y % 400 == 0 ) );
}

int daysInMonth ( int m, int y )
{
	switch ( m )
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
			return 28 + isLeapYear ( y );
	}
	return -1;
}

int isValidDate ( int d, int m, int y )
{
	return y > 1600 && m > 0 && m < 13 && d > 0 && d <= daysInMonth ( m, y );
}

int readDate ( int * d, int * m, int * y )
{
	return scanf ( "%d/%d/%d", d, m, y ) == 3 && isValidDate ( *d, *m, *y );
}

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

const char * monthOfTheYear ( int month )
{
	switch ( month )
	{
		case 1: return "leden";
		case 2: return "unor";
		case 3: return "brezen";
		case 4: return "duben";
		case 5: return "kveten";
		case 6: return "cerven";
		case 7: return "cervenec";
		case 8: return "srpen";
		case 9: return "zari";
		case 10: return "rijen";
		case 11: return "listopad";
		case 12: return "prosinec";
	}
	return NULL;
}

int daysUntil ( int d, int m, int y )
{
	int i, sum = 0;
	for ( i = 1; i < m; i ++ )
		sum += daysInMonth ( i, y );
	return sum + d - 1;
}

int weeksUntil ( int d, int m, int y, int offset )
{
	return ( daysUntil ( d, m, y ) + offset ) / 7;
}

int dayFromDate ( int d, int m, int y, int offset )
{
	return ( daysUntil ( d, m, y ) + offset ) % 7;
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

