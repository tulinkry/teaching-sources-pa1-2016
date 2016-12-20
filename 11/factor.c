#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factor ( int n )
{
	int i;
	double sqrtn = sqrt ( n ) + 0.5;
	
	for ( i = 2; i <= sqrtn; i ++ )
	{	
		if ( n % i == 0 )
		{
			printf ( "%d * ", i );
			factor ( n / i );
			return;
		}
	}
	printf ( "%d", n );
}

int main ( int argc, const char * argv[] )
{
	int n;

	if ( argc < 2 )
	{
		printf ( "Usage: %s <n>\n", argv [ 0 ] );
		return 1;	
	}

	// atoi () - nelze kontrolovat chybu
	// sscanf () - lze kontrolovat chybu
	if ( sscanf ( argv [ 1 ], "%d", &n ) != 1 )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}

	printf ( "%d = ", n );
	factor ( n );
	printf ( "\n" );


	return 0;
}
