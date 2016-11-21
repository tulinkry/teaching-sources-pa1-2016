#include <stdio.h>
#include <assert.h>

/**
 * Program obsahuje funkci, která usnadňuje rozhodnutí o výsledku bitvy, jež se 
 * zúčastnily pozemní jednotky.
 *
 * Ztráty na obou stranách počítá procentuelně podle zastoupení v celkové síle
 * všech jednotek v bitvě.
 *
 * Zároveň opět demonstruje použítí assertu pro jednoduché testování.
 */

#define INFANTRY_POWER 1
#define TANK_POWER 5

int max ( int a, int b )
{
	return a < b ? b : a;
}

int battle ( int * infantryAttack, int * tanksAttack,
			 int * infantryDefense,  int * tanksDefense )
{
	int defender, attacker;

	defender = *infantryDefense * INFANTRY_POWER + *tanksDefense * TANK_POWER;
	attacker = *infantryAttack * INFANTRY_POWER + *tanksAttack * TANK_POWER;

	*infantryDefense *= defender / ( double ) ( attacker + defender );
	*tanksDefense *= defender / ( double ) ( attacker + defender );

	*infantryAttack *= attacker / ( double ) ( attacker + defender );
	*tanksAttack *= attacker / ( double ) ( attacker + defender );

	return attacker - defender;
}

void testResults ( void )
{
	int iA, tA, iD, tD;

	iA = 1, tA = 0, iD = 0, tD = 0;
	assert ( battle ( &iA, &tA, &iD, &tD ) > 0 && iA == 1 && tA == 0 && iD == 0 && tD == 0 );
	iA = 0, tA = 1, iD = 0, tD = 0;
	assert ( battle ( &iA, &tA, &iD, &tD ) > 0 && iA == 0 && tA == 1 && iD == 0 && tD == 0 );
	iA = 0, tA = 0, iD = 1, tD = 0;
	assert ( battle ( &iA, &tA, &iD, &tD ) < 0 && iA == 0 && tA == 0 && iD == 1 && tD == 0 );
	iA = 0, tA = 0, iD = 0, tD = 1;
	assert ( battle ( &iA, &tA, &iD, &tD ) < 0 && iA == 0 && tA == 0 && iD == 0 && tD == 1);
}

void testDeaths ( void )
{
	int iA, tA, iD, tD;

	iA = 100, tA = 0, iD = 50, tD = 0;
	assert ( battle ( &iA, &tA, &iD, &tD ) > 0 && tA == 0 && tD == 0 && iA == 66 && iD == 16 );
	iA = 50, tA = 0, iD = 100, tD = 0;
	assert ( battle ( &iA, &tA, &iD, &tD ) < 0 && tA == 0 && tD == 0 && iA == 16 && iD == 66);
	iA = 100, tA = 200, iD = 200, tD = 100;
	assert ( battle ( &iA, &tA, &iD, &tD ) > 0 && iA == 61 && tA == 122 && iD == 77 && tD == 38 );
	iA = 100, tA = 200, iD = 700, tD = 100;
	assert ( battle ( &iA, &tA, &iD, &tD ) < 0 && iA == 47 && tA == 95 && iD == 365 && tD == 52 );
	iA = 100, tA = 100, iD = 100, tD = 100;
	assert ( battle ( &iA, &tA, &iD, &tD ) == 0 && iA == 50 && tA == 50 && iD == 50 && tD == 50 );
	iA = 300, tA = 300, iD = 800, tD = 200;
	assert ( battle ( &iA, &tA, &iD, &tD ) == 0 && iA == 150 && tA == 150 && iD == 400 && tD == 100 );
}

void tests ( void )
{
	testResults ();
	testDeaths ();
}

int main ( void )
{
	tests ();
	return 0;
}
