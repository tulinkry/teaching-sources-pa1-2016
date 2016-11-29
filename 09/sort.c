#include <stdio.h>
#include <stdlib.h>

void sortArray ( int * array, int len, int orderBy )
{

}

int main ( void )
{
	int * array;
	int size = 0, sizeMax = 6;
	int i;

	if ( ! ( array = ( int * ) malloc ( sizeMax * sizeof ( int ) ) ) )
	{
		printf ( "Nespravna alokace.\n" );
		return 1;
	}

	while ( 1 )
	{
		if ( size == sizeMax )
		{
			if ( ! ( array = ( int * ) realloc ( array, sizeMax * 2 * sizeof ( int ) ) ) )
			{
				printf ( "Nespravna alokace.\n" );
				return 1;
			}
			sizeMax *= 2;
		}

		if ( ! ( scanf ( "%d", &array[size] ) == 1 ) )
			break;

		size ++;
	}

	if ( ! feof ( stdin ) )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}


	for ( i = 0; i < size; i ++ )
		printf ( "%d ", array[i] );
	printf ( "\n" );

	sortArray ( array, size, 1 );

	for ( i = 0; i < size; i ++ )
		printf ( "%d ", array[i] );
	printf ( "\n" );


	free ( array );
	return 0;
}
