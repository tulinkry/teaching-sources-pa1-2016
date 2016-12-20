#include <stdio.h>
#include <stdlib.h>

/**
 * Priklad na manipulaci s jednosmerne zretezenym spojovym seznamem s ukazateli
 * na zacatek a na konec seznamu.
 */

typedef struct Rectangle
{
	int m_Width;
	int m_Height;
	char m_Colour;
	struct Rectangle * m_Next;
} RECT;

int isEmpty ( RECT * head, RECT * tail);

void add2Head ( int w, int l, char colour, RECT ** head, RECT ** tail )
{
	RECT * n;

	n = ( RECT * ) malloc ( sizeof ( *n ) );

	n -> m_Width = w;
	n -> m_Height = l;
	n -> m_Colour = colour;
	n -> m_Next = *head;

	if ( isEmpty ( *head, *tail ) )
		*tail = n;
	*head = n;
}

void add2Tail ( int w, int l, char colour, RECT ** head, RECT ** tail )
{
	RECT * n;

	n = ( RECT * ) malloc ( sizeof ( *n ) );

	n -> m_Width = w;
	n -> m_Height = l;
	n -> m_Colour = colour;
	n -> m_Next = NULL;

	if ( isEmpty ( *head, *tail ) )
		*head = *tail = n;
	else
	{
		(*tail) -> m_Next = n;
		*tail = n;
	}
}

void createEmpty ( RECT ** head, RECT ** tail )
{
	*head = NULL;
	*tail = NULL;
}

void printList ( RECT * head )
{
	while ( head ) // ekvivalentni s head != NULL
	{
		printf ( "sirka = %d, vyska = %d, barva = %c\n", head -> m_Width, 
														 head -> m_Height, 
														 head -> m_Colour);
		head = head -> m_Next;
	}
}

void delete ( RECT * head )
{
	RECT * i;

	while ( head )
	{
		i = head -> m_Next;
		free ( head );
		head = i;
	}
}

int isEmpty ( RECT * head, RECT * tail)
{
	if ( head == NULL)
		return 1;
	else
		return 0;
	// nebo tez
	// return head == NULL;
}

int count ( RECT * head )
{
	int i = 0;

	while ( head )
	{
		i ++;
		head = head -> m_Next;
	}

	return i;
}

int main ( void )
{
	RECT * head, * tail;

	createEmpty ( &head, &tail );
	add2Head ( 4, 5, 'y', &head, &tail );
	add2Head ( 14, 3, 'b', &head, &tail );
	printList ( head );
	add2Tail ( 10, 4, 'r', &head, &tail );
	add2Tail ( 12, 9, 'o', &head, &tail );
	printList ( head );
	printf ( "pocet prvku: %d\n",count ( head ) );
	delete ( head );

	return 0;
}
