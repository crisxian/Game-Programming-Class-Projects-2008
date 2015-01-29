#include "stdafx.h"
#include <conio.h>
#include <io.h>
#include <dos.h>
#include <stdio.h>
#include <iostream>
#include "cards.h"

Card::Card(int val)
{
	value = val;
}

void Card::Display(int face)
{
	if (face == FACEUP)
		ShowFace();
	else
		ShowBack();
}

void Card::ShowFace()
{
	int value;
	char* suit;
	value = (int) (GetValue()/13);
	switch(value)
	{
		case (0): 
			suit = "DIAMONDS";
			printf("card:%d, face:%s       \n", GetValue()%13,  suit );
			break;
		case (1):
			suit = "CLUBS";
			printf("card:%d, face:%s       \n", GetValue()%13,  suit );
			break;
		case (2):
			suit = "SPADE";
			printf("card:%d, face:%s       \n", GetValue()%13,  suit );
			break;
		case (3):
			suit = "HEART";
			printf("card:%d, face:%s       \n", GetValue()%13,  suit );
			break;
	}
}

void Card::ShowBack()
{
	printf ("Back             \n");
}

Deck::Deck()
{
	char s[15];

	rand();
	positionInDeck = 0;

	for (int x = 0; x < 52; ++x)
	{
		cards[x] = new Card(x);
	}
	InitHands();
}

Deck::~Deck()
{
	for (int x = 0; x < 52; ++x)
		delete cards[x];
}

void Deck::Shuffle()
{
	int x, cardNum;
	Card *temp;

	positionInDeck = 0;

	for (x = 0; x < 52; ++x)
	{
		cardNum =  rand() % 52;
		temp = cards[x];
		cards[x] = cards[cardNum];
		cards[cardNum] = temp;
	}
	InitHands();
}

void Deck::Deal(int num, int hand, int face)
{
	int pos;

	for (int z = 0; z < num; ++z)
	{
		pos = hands[hand].positionInHand;
		hands[hand].cards[pos] = cards[positionInDeck];
		cards[positionInDeck] ->Display (face);
			++positionInDeck;

		if (positionInDeck > 51)
			positionInDeck = 0;

		hands[hand].positionInHand++;

		if (hands[hand].positionInHand > 51)
			hands[hand].positionInHand = 0;
	}
}

void Deck::ShowHand(int hand, int pos, int face)
{
	int num = hands[hand].positionInHand;

	for (int z = 0; z < num; ++z)
	{
		hands[hand].cards[z]->Display(face);
	}
}

void Deck::DealReplace(int hand, int pos, int face)
{
	int x, y;

	hands[hand].cards[pos] = cards[positionInDeck];

	cards[positionInDeck]->Display(face);
		++positionInDeck;

	if (positionInDeck > 51)
	{
		positionInDeck = 0;
	}
}

void Deck::Discard(int hand, int pos)
{
	int x, y;

	int discardPos = hands[MAXHANDS-1].positionInHand++;
	hands[MAXHANDS-1].cards[discardPos] = hands[hand].cards[pos];

	for (int j = pos; j < hands[hand].positionInHand; ++j)
		hands[hand].cards[j] = hands[hand].cards[j+1];

	--hands[hand].positionInHand;
}

void Deck::ShowHandCard(int hand, int pos, int face)
{
	if (face == FACEUP)
		hands[hand].cards[pos]->ShowFace();
	else
		hands[hand].cards[pos]->ShowBack();
}

int  Deck::GetCardValue(int hand, int pos)
{
	return hands[hand].cards[pos]->GetValue();
}

void Deck::GetHand(int handNum, Hand &hand)
{
	memcpy (&hand, &hands[handNum], sizeof(hand));
}

void Deck::InitHands()
{
	int x, y;

	for (x = 0; x < MAXHANDS; ++x)
	{
		hands[x].positionInHand = 0;

		for ( y = 0; y < 52; ++y)
			hands[x].cards[y] = NULL;
	}
}
