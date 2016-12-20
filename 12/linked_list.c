#include <stdio.h>
#include <stdlib.h>

typedef struct TElement
{
	int m_Value;
	struct TElement * m_Next;
} TELEMENT;

TELEMENT * AddElement ( int value, TELEMENT * head ) 
{
	TELEMENT * tmp = ( TELEMENT * ) malloc ( sizeof ( *tmp ) );
	tmp -> m_Value = value;
	tmp -> m_Next = head;
	return tmp; 
}

void PrintLinkedList ( TELEMENT * head )
{
	while( head )
	{
		printf ( "%d, ", head -> m_Value );
		head = head -> m_Next;
	}
	printf( "\n" );
}

void DeleteLast ( TELEMENT ** head )
{
	TELEMENT * tmp = *head;
	TELEMENT * p = NULL;

	if ( !tmp )
		return;

	while ( tmp -> m_Next )
	{
		p = tmp;
		tmp = tmp -> m_Next;
	}

	if ( p == NULL && tmp == *head )
		*head = NULL;
	else
		p -> m_Next = NULL;

	free ( tmp );
}

/**
 * Vysoce neefektivni mazani spojoveho seznamu, lepsi reseni je iterativne
 * @param head ukazatel na zacatek spojoveho seznamu
 */
void FreeLinkedList ( TELEMENT * head )
{
	if ( head )
		FreeLinkedList( head -> m_Next );
	free( head );
}

int main(void)
{
	TELEMENT * head = NULL;
	head = AddElement ( 5, head );
	head = AddElement ( 10, head );
	head = AddElement ( 15, head );
	PrintLinkedList ( head );
	head = AddElement ( 10, head );
	head = AddElement ( 15, head );
	PrintLinkedList ( head );
	DeleteLast ( &head );
	PrintLinkedList ( head );
	DeleteLast ( &head );
	DeleteLast ( &head );
	PrintLinkedList ( head );
	FreeLinkedList ( head );
	return 0;
}
