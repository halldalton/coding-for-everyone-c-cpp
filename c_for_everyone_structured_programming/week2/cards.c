/*
  Monte Carlo Simulation of
  Poker Hand Probability
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum s
{
	spades,
	clubs,
	hearts,
	diamonds
} s;


typedef struct card
{
	s suit;
	short pip;
} card;


void swap(card *card1, card *card2) // used in the shuffle function
{
	card temp = *card1;
	*card1 = *card2;
	*card2 = temp;
}


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


void shuffle_deck(card d[])
{
	srand(time(0)); // set random seed

	int i, r;
	
	for (i = 0; i < 52; i++)
    {
        r = i + (rand() % (52 - i)); // choses random card from  remaining deck to swap with
  
        swap(&d[i], &d[r]);
    }
}


void print_deck(card d[], int n)
{
	for (int i = 0; i < n; i ++)
	{
		if (i % 13 == 0)
		{
			printf("\n");
		}
		printf("%d, %d\t", d[i].suit, d[i].pip);
	}
}


void check_pairs(card h[], int *no_p, int *one_p, int *two_p, int *three_p, int *four_p, int *f_house)
{
	int i, j, no_pairfull_house = 0;
	int pairs[6] = {0};

	for (i = 0; i < 7; i++)
	{
		int pip1 = h[i].pip;

		for (j = i + 1; j < 7; j++)
		{
			int pip2 = h[j].pip;

			if (pip1 == pip2)
			{
				pairs[i] += 1;
			}
		}
	}

	for (int k = 0; k < 6; k++)
	{
		printf("%d\t", pairs[k]);

	}
}


int main(void)
{
	const int NUM_HANDS = 1;
	int i, j, k;
	int no_pair = 0, one_pair = 0, two_pair = 0, three_of_a_kind = 0, four_of_a_kind = 0, full_house = 0; // initialize probability counts
	card deck[52], hand[7];

	populate_deck(deck);

	for (i = 0; i < NUM_HANDS; i++)
	{
		j = i % 7; // after 7 deals, the cards need to be reshuffled

		if (j == 0)
		{
			shuffle_deck(deck);
		}

		for (k = 0; k < 7; k++) // gets 0-6 first hand, 7-13 second hand, etc.
		{
			hand[k] = deck[k + (7 * j)];
		}

		print_deck(hand, 7);
		printf("\n\n");
		check_pairs(hand, &no_pair, &one_pair, &two_pair, &three_of_a_kind, &four_of_a_kind, &full_house);
		printf("\n\n");
	}
}	
