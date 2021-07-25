/*
  Cards
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>

typedef enum suit
{
	spades,
	clubs,
	hearts,
	diamonds
} suit;


typedef struct card
{
	suit s;
	short pip;
} card;


void populate_deck(card d[])
{
	int i, j, k = 0;

	for (i = spades; i <= diamonds; i++)
	{
		for (j = 0; j < 13; j++)
		{
			d[k] = (card){i, j};
			k++;
		}
	}
}


void shuffle_deck(char *d)
{

}


int main(void)
{
	card deck[52];
	populate_deck(&deck);
}	
