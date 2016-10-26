#include <stdio.h>

/**
 * Program načte ze vstupu sekvenci identifikující položky v automatu na vratné lahve.
 *
 * 1) láhev je identifikována jako 'b'
 * 2) přepravka je identifikována jako 'p'
 * 		u přepravky je dodatečně nutné zadat, desetinné číslo, které popisuje, v jakém je stavu
 * 3) sud je identifikován jako 'k'
 * 		u sudu lze písmeny s, m, l určit jeho velikost
 *
 * Na výstup vypíše, kolik dostane uživatel za zpracovaný seznam peněz. Program se přitom drží
 * základních pravidel:
 * 1) láhev je za 3 peníze
 * 2) přepravka je za 100 * koeficient kvality
 * 3) sud velikosti m stojí 1000
 * 		l stojí 2x tolik (tedy 2000)
 * 		s stojí polovinu (tedy 500)
 */

#define BOTTLE_DEPOSIT 3
#define PACK_DEPOSIT 100
#define KEG_DEPOSIT 1000

int main ( void )
{
	char type;
	double brand, sum = 0;

	while ( 1 )
	{
		if ( ! ( scanf ( " %c", &type ) == 1 ) )
			break;

		switch ( type )
		{
			case 'p':
			case 'P':
				if ( ! ( scanf ( "%lf", &brand ) == 1 &&
						 brand > 0 ) )
				{
					printf ( "Nespravny vstup.\n" );
					return 1;
				}
				sum += PACK_DEPOSIT * brand;
			break;
			case 'b':
			case 'B':
				sum += BOTTLE_DEPOSIT;
			break;
			case 'k':
			case 'K':
				if ( ! ( scanf ( "%c", &type ) == 1 &&
						 ( type == 's' || type == 'm' || type == 'l' ) ) )
				{
					printf ( "Nespravny vstup.\n" );
					return 1;
				}
				switch ( type )
				{
					case 's': sum += KEG_DEPOSIT * 0.5; break;
					case 'm': sum += KEG_DEPOSIT * 1; break;
					case 'l': sum += KEG_DEPOSIT * 2; break;
				}
			break;
			default:
				printf ( "Nespravny vstup.\n" );
				return 1;

		}
	}

	if ( ! feof ( stdin ) )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}


	printf ( "Penize k vraceni: %g.\n", sum );

	return 0;
}
