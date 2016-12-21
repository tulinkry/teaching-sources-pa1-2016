#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
	int m_value;
	struct tree * m_R;
	struct tree * m_L;
} TREE;

void destroyTree ( TREE * root )
{
	if ( root == NULL )
		return;

	destroyTree ( root -> m_R );
	destroyTree ( root -> m_L );
	free ( root );
}

void printTreePreOrder ( TREE * root, int depth )
{
	int i;
	if ( root == NULL )
		return;

	printTreePreOrder ( root -> m_L, depth + 1 );
	printTreePreOrder ( root -> m_R, depth + 1 );

	for ( i = 0; i < depth; i++ )
		printf ( " " );
	printf ( "%d\n", root -> m_value );

	return;
}

void printTreeInOrder ( TREE * root, int depth )
{
	int i;
	if ( root == NULL )
		return;

	printTreeInOrder ( root -> m_L, depth + 1 );

	for ( i = 0; i < depth; i++ )
		printf ( " " );

	printf ( "%d\n", root -> m_value );

	printTreeInOrder ( root -> m_R, depth + 1 );
	return;
}

void printTreePostOrder ( TREE * root, int depth )
{
	int i;
	if ( root == NULL )
		return;

	for ( i = 0; i < depth; i++ )
		printf ( " " );
	printf ( "%d\n", root -> m_value );

	printTreePostOrder ( root -> m_L, depth + 1 );
	printTreePostOrder ( root -> m_R, depth + 1 );
	return;
}

int insTree ( TREE ** root, int num )
{
	if ( (*root) == NULL )
	{
		*root = ( TREE * ) malloc ( sizeof ( TREE ) );
		(*root) -> m_value = num;
		(*root) -> m_L = NULL;
		(*root) -> m_R = NULL;
		return 1;
	}

	if ( num == (*root) -> m_value )
		return 0;
	else if ( num < (*root) -> m_value )
		return insTree( &( (*root) -> m_L ), num );
	else
		return insTree( &( (*root) -> m_R ), num );
}

int insTreeItPtr ( TREE ** root, int num )
{
	TREE * tmp = *root, **insertPlace = root;

	while ( tmp ){
		if ( num < tmp -> m_value ){
			insertPlace = &tmp->m_L;
			tmp = tmp -> m_L;
		} else if ( num > tmp -> m_value ){
			insertPlace = &tmp->m_R;
			tmp = tmp -> m_R;
		} else
			return 0;
	}

	*insertPlace = ( TREE * ) malloc ( sizeof ( TREE ) );
	(*insertPlace) -> m_value = num;
	(*insertPlace) -> m_R = NULL;
	(*insertPlace) -> m_L = NULL;

	return 1;
}


int insTreeIt ( TREE ** root, int num )
{
	TREE * tmp = (*root);

	if ( tmp == NULL )
	{
		*root = ( TREE * ) malloc ( sizeof ( TREE ) );
		(*root) -> m_value = num;
		(*root) -> m_L = NULL;
		(*root) -> m_R = NULL; 
		return 1;
	}

	/**
	 * Podminka funguje do te doby, dokud jsem nenarazil na misto, kam bych mohl vlozit nove cislo
	 * - mel bych jit doleva, ale nic tam neni nebo
	 * - mel bych jit doprava, ale nic tam neni
	 */
	while ( ! ( ( num < tmp -> m_value && tmp -> m_L == NULL ) || 
				( num > tmp -> m_value && tmp -> m_R == NULL ) ) )
	{
		if ( num < tmp -> m_value ) {
			tmp = tmp -> m_L;
		} else if ( num > tmp -> m_value ){
			tmp = tmp -> m_R;
		} else {
			return 0;
		}
	}

	/**
	 * V tuto chvili je v tmp uzel, pod ktery bych mel pripojit novy uzel.
	 * Musim se jen rozhodnout, jestli doleva nebo doprava
	 */

	if ( num < tmp -> m_value )
	{
		tmp -> m_L = ( TREE * ) malloc ( sizeof ( TREE ) );
		tmp = tmp -> m_L;
	}
	else 
	{
		tmp -> m_R = ( TREE * ) malloc ( sizeof ( TREE ) );
		tmp = tmp -> m_R;
	}

	tmp -> m_value = num;
	tmp -> m_R = NULL;
	tmp -> m_L = NULL;
	return 1;
}



int main ( int argc, char * argv[] )
{
	int i, n, num;
	TREE * root = NULL;

	if ( argc < 2 )
	{
		printf ( "Usage: %s <n>\n", argv [ 0 ] );
		return 2;
	}

	if ( sscanf ( argv[1], "%d", &n ) != 1 || n < 1 )
	{
		printf ( "Nespravny vstup.\n" );
		return 1;
	}

	for ( i = 0; i < n; i++ )
	{
		num = rand() % 20;

		if ( insTreeIt( &root, num ) )
			printf( "%d, ", num );
		else
			printf( "(already exists: %d), ", num );
	}
	printf ( "\n" );

	printf ( " ----------------- pre order ----------------- \n" );
	printTreePreOrder ( root, 0 );
	printf ( " ----------------- in order ----------------- \n" );
	printTreeInOrder ( root, 0 );
	printf ( " ----------------- post order ----------------- \n" );
	printTreePostOrder ( root, 0 );

	destroyTree ( root );
	return 0;
}
