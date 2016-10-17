#include <stdio.h>

/**
 * Program na základní vstup a výstup.
 *
 * Program načte dvě celá čísla symbolizující strany dvou čtverců.
 * Ověří, že první čtverec je větší než druhý a následně vypíše
 * kolikrát se menší čtverec vejde do většího.
 */

int main ( void )
{
    int firstSquare, secondSquare;

    if ( ! ( scanf ( "%d %d", &firstSquare, &secondSquare ) == 2 &&
                     firstSquare >= secondSquare ) )
    {
            printf ( "Nespravny vstup.\n" );
            return 3;
    }

    firstSquare *= firstSquare;
    secondSquare *= secondSquare;

    printf ( "M v V ~ %fx\n", ((double) firstSquare) / secondSquare );

    return 0;
}
