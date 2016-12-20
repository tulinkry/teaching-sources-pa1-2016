#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIBONACCI_NUMBER 301

int fibonacci ( int n, int * cnt )
{
	if ( n <= 2 )
		return 1;
	(*cnt) ++;
	return fibonacci ( n - 1, cnt ) + fibonacci ( n - 2, cnt );
}

int fibonacci_opt ( int n, int * cache, int * cnt )
{
	if ( n <= 2 )
		return 1;
	if ( cache [ n ] )
		return cache [ n ];

	(*cnt) ++;
	return cache [ n ] = fibonacci_opt ( n - 1, cache, cnt ) + fibonacci_opt ( n - 2, cache, cnt );
}

int factorial ( int n )
{
	if ( n <= 1 )
		return 1;
	return n * factorial ( n - 1 );
}


int main ( int argc, const char * argv[] )
{
	int n;
	int cnt = 0;
	int cache [ MAX_FIBONACCI_NUMBER ];

	if ( argc < 3 )
	{
		printf ( "Usage: %s <function> <n>\n", argv [ 0 ] );
		return 1;
	}

	if ( strcmp ( "fact", argv [ 1 ] ) == 0 )
	{
		n = atoi ( argv [ 2 ] );
		printf ( "%d! = %d\n", n, factorial ( n ) );
	}
	else if ( strcmp ( "fib", argv [ 1 ] ) == 0 && sscanf ( argv [ 2 ], "%d", &n ) == 1 )
	{
		printf ( "fibonacci(%d) = %d\n", n, fibonacci ( n, &cnt ) );
		printf ( "pocet volani: %d\n", cnt );
	}
	else if ( strcmp ( "fib2", argv [ 1 ] ) == 0 && sscanf ( argv [ 2 ], "%d", &n ) == 1 && n < MAX_FIBONACCI_NUMBER )
	{
		memset ( cache, 0, MAX_FIBONACCI_NUMBER * sizeof ( int ) );
		printf ( "fibonacci_opt(%d) = %d\n", n, fibonacci_opt ( n, cache, &cnt ) );
		printf ( "pocet volani: %d\n", cnt );
	}
	else
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}


	return 0;
}
