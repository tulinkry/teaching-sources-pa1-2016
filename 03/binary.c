#include <stdio.h>

/**
 * Program načte celé číslo ze vstupu a vypíše jeho binární reprezentaci v počítači.
 *
 * Stojí za povšimnutí, že pokud použijeme jiný typ pro proměnnou a a správnou
 * vstupní a výstupní konverzi, funguje toto řešení univerzálně.
 */

/** příkaz preprocesoru */
#define BITS_PER_BYTE 8

int main ( void )
=======
{
	int a;
	int i, j;
	
	if ( ! ( scanf ( "%d", &a ) == 1 ) )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}

	printf ( "Pozpatku: " );
	for ( i = 0; i < sizeof ( a ); i ++ ) 
		for ( j = 0; j < BITS_PER_BYTE; j ++ )
			printf ( "%1d", ( a >> ( BITS_PER_BYTE * i + j ) ) & 0x1 );
	printf ( "\n" );

	printf ( "Normalne: " );
	for ( i = 0; i < sizeof ( a ); i ++ ) 
		for ( j = 0; j < BITS_PER_BYTE; j ++ )
			printf ( "%1d", ( a >> ( sizeof ( a ) * BITS_PER_BYTE - 1 - ( BITS_PER_BYTE * i + j ) ) ) & 0x1 );
	printf ( "\n" );


	return 0;
}
