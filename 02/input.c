#include <stdio.h>

/**
 * Program na základní vstup a výstup. Načte tři celá čísla a vypíše je.
 */

int main ( void )
{
    int a, b, c;

    if ( ! ( scanf ( "%d %d %d", &a, &b, &c ) == 3 &&
                     a < b && b < c ) )
    {
            printf ( "Nespravny vstup.\n" );
            return 1;
    }

    printf ( "a = %#x, b = %03d, c = %0100d\n", a, b, c );

    return 0;
}
