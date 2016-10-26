#include <stdio.h>
#include <math.h>
#include <float.h>

/**
 * Program načte zlomky ve tvaru a/b ze vstupu a porovná, jestli jejich součet
 * dohromady dává 1.
 */

int main(int argc, char const *argv[])
{
	int a, b;
	double sum = 0;

	/* zdánlivě nekonečný cyklus */
	while ( 1 )
	{
		if ( ! ( scanf ( "%d/%d", &a, &b ) == 2 && a > 0 && b > 0 ) )
			/* scanf nenačetla, co jsme chtěli:
			 *	- konec vstupu
			 *	- špatně zadaný vstup
			 */
			break;

		/* v tuto chvíli máme ošetřený vstup každé iterace a můžeme provést výpočet */
		sum += (double) a / b;
	}

	/* sem sme se dostali, protože se provedl break v cyklu */
	/* nyní jsou dvě varianty:
	 * - vstup byl validní - tedy jsme na konci souboru (vše jsme přečetli správně)
	 * - vstup nebyl validní - a tedy nejsme na konci vstupu (čtení selhalo na nějakém neznámém znaku)
	 */
	if ( ! feof ( stdin ) )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}

	/* v tuto chvíli máme ošetřený celkový vstup a můžeme provést výpočet/výpis atd. */

	if ( fabs ( sum - 1.0 ) / sum < 100 * DBL_EPSILON )
		printf ( "Soucet zlomku je 1.\n" );
	else
		printf ( "Soucet zlomku neni 1.\n" );

	return 0;
}
