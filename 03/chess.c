#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Program načte ze vstupu dvě souřadnice ve formátu <písmeno><číslo>,
 * kde písmeno je z intervalu a-h a číslo z intervalu 1-8 (jako v šachách).
 *
 * Pro dané dvě souřadnice vypíše manhattanskou a euklidovu vzdálenost.
 *
 * POZOR: kompilujeme s přepínačem -lm (kvůli math.h)
 */

int main ( void )
{
	char x1, x2;
	int y1, y2;

	if ( ! ( scanf ( " %c%d", &x1, &y1 ) == 2 && x1 >= 'a' && x1 <= 'h' + 8 && y1 >= 1 && y1 <= 8 ) )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}

	if ( ! ( scanf ( " %c%d", &x2, &y2 ) == 2 && x2 >= 'a' && x2 <= 'h' && y2 >= 1 && y2 <= 8 ) )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}


	printf ( "Manhattanska vzdalenost %c%d a %c%d je %d.\n", x1, y1, x2, y2,
		abs ( x2 - x1 ) + abs ( y2 - y1 ) );
	printf ( "Euklidovska vzdalenost %c%d a %c%d je %.3f.\n", x1, y1, x2, y2, 
		sqrt ( ( x2 - x1 ) * ( x2 - x1 ) + ( y2 - y1 ) * ( y2 - y1 ) ) );

	return 0;
}
