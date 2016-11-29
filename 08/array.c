#include <stdio.h>
#include <stdlib.h>

int fillArray ( int * array, int len )
{
	int i;
	for ( i = 0; i < len; i ++ )
		if ( ! ( scanf ( "%d", &array[i] ) == 1 ) )
			return 0;
	return 1;
}

void printArray ( int * ptr, int len )
{
	int i;
	for ( i = 0; i < len; i ++ )
		printf ( "%3d", ptr[i] );
	printf ( "\n" );
}

int allocateArray ( int ** ptr, int len )
{
	return ( *ptr = ( int * ) malloc ( len * sizeof ( int ) ) ) != NULL;
}

int main ( void )
{
	int len;
	int * ptr;

	if ( ! ( scanf ( "%d", &len ) == 1 && len > 0 ) )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}

	if ( ! allocateArray ( &ptr, len ) )
	{
		printf ( "Nespravna alokace.\n" );
		return 1;
	}

	if ( ! fillArray ( ptr, len ) )
	{
		printf ( "Nespravny vstup.\n" );
		free ( ptr );
		return 1;
	}

	printArray ( ptr, len );

	free ( ptr );

	return 0;
}
