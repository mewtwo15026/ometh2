/*
 * card.h
 *
 *  Created on: Oct 1, 2014
 *      Author: sean
 */

#ifndef CARD_H_
#define CARD_H_

using namespace std;


class card {
public:
	enum Suit {
		Club, Diamond, Heart, Spade
	};
	enum Value {
		ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
	};
	string valStrRep[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
	string suitStrRep[4] = {"Club", "Diamond", "Heart", "Spade"};

	Value getFace() const
	{
		return face;
	}

	void setFace(Value face)
	{
		this->face = face;
	}

	Suit getSuit() const
	{
		return suit;
	}

	void setSuit(Suit suit)
	{
		this->suit = suit;
	}

	card(int suit, int val)
	//TODO Ensure invariant of suit <= 4, face <= 13
	{
		this->suit = suit;
		this->face = val;
	}
	friend ostream& operator << (ostream& ostr, card& card)
	{
		ostr << valStrRep[card.face] << " of " << suitStrRep[card.suit] << endl;
		return ostr;
	} // end operator <<

private:
	Suit suit;
	Value face;
};



#endif /* CARD_H_ */
