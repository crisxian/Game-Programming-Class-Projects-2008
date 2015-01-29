// blackjack final.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <io.h>
#include <dos.h>
#include <stdio.h>
#include <iostream>
#include "cards.h"

const int ENTER = 13;
const int SPACE = 32;
const int ESC   = 27;
const int DEALER = 0;
const int PLAYER = 1;

int cardCount1, cardCount2;

Deck deck;

int GetCardTotal (int player);
void StartGame(void);
int PlayerTurn(void);
int DealerTurn(void);
int PlayAgain(void);
void ShowResults(int playerTotal, int dealerTotal);

void main(void)
{
	int playerTotal, dealerTotal, done;
//	int valD = deck.GetCardValue(DEALER, 0) % 13;
	do
	{
		StartGame();
		playerTotal = PlayerTurn();

		if (playerTotal < 22)
			dealerTotal = DealerTurn();
		else
			dealerTotal = GetCardTotal(DEALER);

		deck.ShowHandCard(DEALER, 0, FACEUP);
		ShowResults(playerTotal, dealerTotal);

		done = PlayAgain();
	}

	while (!done);

	
}

void ShowResults(int playerTotal, int dealerTotal)
{
	if (((playerTotal < 22) && (playerTotal > dealerTotal)) || (dealerTotal > 21))
		printf ( "YOU WIN!\n");

	else if (playerTotal == dealerTotal)
		printf ("IT'S A TIE\n");
	
	else
		printf ("YOU LOSE!\n");
}

int PlayAgain(void)
{
	printf ("Press Enter to play again.\n");
	printf ("Press Esc to quit\n");

	int ch = getch();

	if (ch == ESC)
		return 1;
	else
		return 0;
}

int GetCardTotal(int player)
{
	int value;
	int total = 0;
	int aceCount = 0;

	int pos = deck.GetPositionInHand(player);

	for (int x = 0; x < pos; ++x)
	{
		value = deck.GetCardValue(player, x) % 13;
		if (value > TEN)
			value = TEN;

		else if (value == ACE)
		{
			++aceCount;
			value = 10;
		}

		total += value + 1;
	}

	if ((total > 21) && (aceCount))
		total -= aceCount * 10;

	return total;
}

void StartGame(void)
{
	deck.Shuffle();
	cardCount1 = 1;
	cardCount2 = 1;

	deck.Deal(1, DEALER, FACEDOWN);
	deck.Deal(1, DEALER, FACEUP);
	deck.Deal(2, PLAYER, FACEUP);

	printf ("Press ENTER for a hit.\n");
	printf ("Press SPACE to stay\n");
}

int PlayerTurn(void)
{
	int ch, total;

	do
	{
		ch =  getch();

		if (ch ==ENTER)
		{
			++cardCount2;
			deck.Deal(1, PLAYER, FACEUP);
		}
		total = GetCardTotal(PLAYER);
	}
	while ((ch != SPACE) && (total < 22));

	if (total > 21)
		printf ("YOU BUSTED!\n");
	if (ch == SPACE)
		printf("STAY\n");

	return total;
}
int DealerTurn(void)
{
	int ch, total;

	do
	{
		total = GetCardTotal(DEALER);

		if ( total > 21)
			printf ("DEALER BUSTS\n");
		
		else if (total > 16)
			printf ("DEALER STAYS \n");

		else
		{
			++cardCount1;
			deck.Deal(1, DEALER, FACEUP);
		}
	}
	while (total < 17);

	return total;
}
