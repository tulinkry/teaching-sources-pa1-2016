#include <assert.h>
#include <stdio.h>
#include <string.h>

int isLower ( char c )
{
	return c >= 'a' && c <= 'z';
}

int myStrlen ( char * c )
{
	int len = 0;
	while ( * ( c ++ ) )
		len ++;
	return len;
}

void toUpper ( char c[] )
{
	int i, len;
	len = strlen ( c );
	for ( i = 0; i < len; i ++ )
		if ( isLower ( c[i] ) )
			c[i] -= 'a' - 'A';
}

int main ( void )
{
	char str[] = "Ahoj svete!";

	toUpper ( str );

	printf ( "%s\n", str );

	assert ( strcmp ( "AHOJ SVETE!", str ) == 0 );

	return 0;
}
