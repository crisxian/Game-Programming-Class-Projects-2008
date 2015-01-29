#ifndef __CARDS_H
#define __CARDS_H

const int MAXHANDS = 8;

enum { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
enum { DIAMONDS, CLUBS, SPADES, HEARTS };
enum { FACEUP, FACEDOWN};

class Card
{
	protected:
		int value;

	public:
		Card			(int val);
		void Display	(int face);
		void ShowFace	(void);
		void ShowBack	(void);
		int GetValue	(void) 
			{return value;}
};

struct Hand
{
	int positionInHand;
	Card *cards[52];
};

typedef Hand Hands[MAXHANDS];

class Deck
{
	protected:
		Card *cards[52];
		int positionInDeck;
		Hands hands;

	public:
		Deck					(void);
		~Deck					(void);

		void Shuffle			(void);
		void Deal				(int num, int hand, int face);
		void Discard			(int hand, int pos);
		void DealReplace		(int hand, int pos, int face);
		void GetHand			(int handNum, Hand &hand);
		void ShowHand			(int hand, int pos, int face);
		void ShowHandCard		(int hand, int pos, int face);
		
		int GetCardValue	     (int hand, int pos);


		int GetPositionInHand	(int hand)
			{return hands[hand].positionInHand;}
		int GetPositionInDeck	(void)
			{return positionInDeck;}
		void Restore			(void)
			{positionInDeck = 0;}

	protected:
		void InitHands(void);
};

#endif

