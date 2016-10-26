#include <stdio.h>
#include <math.h>

/**
 * Program demonstruje práci s desetinnými čísly při porovnávání.
 *
 * Obvykle se neuvažuje, že by jedno z čísel bylo nekonečno, nicméně
 * jsme to raději zahrnuli, aby bylo vidět, že v desetiných číslech lze reprezentovat
 * nekonečno.
 */

/* doporučuji kompilovat s -Wno-div-by-zero (pouze pro ukázkové účely) */
#define inf ((double)1/0)

/**
 * Compare two floating point numbers
 * @param  a first number
 * @param  b second number
 * @return   0 if they are almost equal, -1 if b is greater, 1 if a is greater
 */
int sgn ( double a, double b )
{
	if ( ( a == inf && b == inf ) || ( a == -inf && b == -inf ) )
		return 0;
	else if ( ( a == inf ) || ( b == -inf ) )
		return 1;
	else if ( ( b == inf ) || ( a == -inf ) )
		return -1;
	

	if ( a - b > 1e-10 * fabs ( a + b ) / 2 )
		return 1;
	else if ( a - b < -1e-10 * fabs ( a + b ) / 2 )
		return -1;
	else
		return 0;
}

int main ( void )
{
	printf( "sgn ( 5.1, 10.6 ) = %d\n", sgn ( 5.1, 10.6 ) );
	printf( "sgn ( -164.5, 0.00042 ) = %d\n", sgn ( -164.5, 0.00042 ) );
	printf( "sgn ( 1e-100, 1e-101 ) = %d\n", sgn ( 1e-100, 1e-101 ) );
	printf( "sgn ( 1.0000000000001e-80, 1.0000000000002e-80 ) = %d\n", sgn ( 1.0000000000001e-80, 1.0000000000002e-80 ) );
	printf( "sgn ( 1.0000000000001e80, 1.0000000000002e80 ) = %d\n", sgn ( 1.0000000000001e80, 1.0000000000002e80 ) );
	printf( "sgn ( inf, 150 ) = %d\n", sgn ( inf, 150 ) );
	printf( "sgn ( -inf, 150 ) = %d\n", sgn ( -inf, 150 ) );
	printf( "sgn ( inf, inf ) = %d\n", sgn ( inf, inf ) );

	return 0;
}
