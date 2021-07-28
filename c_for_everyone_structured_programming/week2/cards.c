/*
  Monte Carlo Simulation of
  Poker h Probability
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
        r = i + (rand() % (52 - i)); // choses random card from remaining deck to swap with
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


void deal_hands(card d[], card h1[], card h2[], card h3[], card h4[], card h5[], card h6[], card h7[])
{
	int i;
	
	for (i = 0; i < 7; i ++)
	{
		h1[i] = d[i];
		h2[i] = d[i + 7];
		h3[i] = d[i + 14];
		h4[i] = d[i + 21];
		h5[i] = d[i + 28];
		h6[i] = d[i + 35];
		h7[i] = d[i + 42];
	}
}


int pip_not_already_checked(int pip, int pips[]) // checks to see if pip has already been checked, so we don't double count pairs
{
	int i;
	for (i = 0; i < 6; i++)
	{
		if (pip == pips[i])
		{
			return 0;
		}
	}
	return 1;
}


void check_hand(card h[], double *np, double *op, double *tp, double *tk, double *fk, double *fh)
{
	int pairs[6] = {0};
	int pips[6] = {-1}; // keep track of pips that we have already checked for pairs.
	int i, j, pair1 = 0, pair2 = 0;

	for (i = 0; i < 6; i ++)
	{
		if (pip_not_already_checked(h[i].pip, pips))
		{
			for (j = 6; j > i; j--)
			{
				if (h[i].pip == h[j].pip)
				{
					pairs[i] += 1;
					pips[i] = h[i].pip;
				}
			}
		}
	}

	for (i = 0; i < 6; i ++)
	{
		if (pairs[i] > 0)
		{
			if (pairs[i] > pair1)  // doing it in this order should always result in pair1 >= pair2
			{
				pair1 = pairs[i];
			}
			else
			{
				if (pairs[i] > pair2)
				{
					pair2 = pairs[i];
				}
			}
		}
	}

	if (pair1 == 3)
	{
		*fk += 1;
	}
	else if (pair1 == 2 && pair2 == 1)
	{
		*fh += 1;
	}
	else if (pair1 == 2 && pair2 == 0)
	{
		*tk += 1;
	}
	else if (pair1 == 1 && pair2 == 1)
	{
		*tp += 1;
	}
	else if (pair1 == 1 && pair2 == 0)
	{
		*op += 1;
	}
	else
	{
		*np += 1;
	}
}


int main(void)
{
	const int NUM_HANDS = 1000006; // multiple of 7
	int i = 0; // initialize iterator
	double no_pair = 0, one_pair = 0, two_pair = 0, three_of_a_kind = 0, four_of_a_kind = 0, full_house = 0; // initialize probability counts
	card deck[52], hand1[7], hand2[7], hand3[7], hand4[7], hand5[7], hand6[7], hand7[7]; // initialize the 7 hands that can be delt from the 52 cards

	populate_deck(deck);

	while (i < NUM_HANDS)
	{
		shuffle_deck(deck);
		deal_hands(deck, hand1, hand2, hand3, hand4, hand5, hand6, hand7);

		check_hand(hand1, &no_pair, &one_pair, &two_pair, &three_of_a_kind, &four_of_a_kind, &full_house);
		i++;

		check_hand(hand2, &no_pair, &one_pair, &two_pair, &three_of_a_kind, &four_of_a_kind, &full_house);
		i++;

		check_hand(hand3, &no_pair, &one_pair, &two_pair, &three_of_a_kind, &four_of_a_kind, &full_house);
		i++;

		check_hand(hand4, &no_pair, &one_pair, &two_pair, &three_of_a_kind, &four_of_a_kind, &full_house);
		i++;

		check_hand(hand5, &no_pair, &one_pair, &two_pair, &three_of_a_kind, &four_of_a_kind, &full_house);
		i++;

		check_hand(hand6, &no_pair, &one_pair, &two_pair, &three_of_a_kind, &four_of_a_kind, &full_house);
		i++;

		check_hand(hand7, &no_pair, &one_pair, &two_pair, &three_of_a_kind, &four_of_a_kind, &full_house);
		i++;
	}

	printf("\n");
	printf("Probabilty of no pair: %lf\n", (no_pair / i));
	printf("Probabilty of one pair: %lf\n", (one_pair / i));
	printf("Probabilty of two pair: %lf\n", (two_pair / i));
	printf("Probabilty of three of a kind: %lf\n", (three_of_a_kind / i));
	printf("Probabilty of full house: %lf\n", (full_house / i));
	printf("Probabilty of four of a kind: %lf\n\n", (four_of_a_kind / i));

	return 0;
}	
