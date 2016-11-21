#include <assert.h>
#include <stdio.h>

int addArray ( int a[], int b[], int alen, int blen )
{
	int i;
	if ( ( alen <= 0 ) || ( blen <= 0 ) || a == NULL || b == NULL )
		return 0;

	for ( i = 0; i < alen && i < blen; i++ )
		a[i]=a[i]+b[i];

	return 1;
}

int main ( void )
{
	int a[] = { 1, 2, 3 };
	int b[] = { 1, 2, 3, 4 };
	int i;

	assert ( addArray ( a, b, 3, 4 ) );

	for ( i = 0; i < 3; i++ )
		printf ( "%3d", a [ i ] );
	printf ( "\n" );

	assert ( ! addArray( NULL, NULL, -1, -1) );

	return 0;
}
