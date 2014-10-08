/*
 * card.h
 *
 *  Created on: Oct 1, 2014
 *      Author: sean
 */

#ifndef CARD_H_
#define CARD_H_

using namespace std;
#include <string>
#include <iostream>

class card {
public:
	// TODO Overloaded assignment operator, even though there's no reason
	// TODO Copy constructor for cards
	enum Suit {
		Club = 0,
		Diamond = 1,
		Heart = 2,
		Spade = 3
	};
	enum Value {
		ACE = 0,
		TWO = 1,
		THREE = 2,
		FOUR = 3,
		FIVE = 4,
		SIX = 5,
		SEVEN = 6,
		EIGHT = 7,
		NINE = 8,
		TEN = 9,
		JACK = 10,
		QUEEN = 11,
		KING = 12
	};

	Value getFace() const;
	void setFace(Value face);
	Suit getSuit() const;
	void setSuit(Suit suit);
	card(int suit, int val);
	card(const card& base);
	friend ostream& operator << (ostream& ostr, card card);
	friend card operator = (const card& rhs);

private:
	Suit suit;
	Value face;
	static std::string valStrRep[13];
	static std::string suitStrRep[4];
};

string card::valStrRep[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};



string card::suitStrRep[4] = {"Club", "Diamond", "Heart", "Spade"};

card::Value card::getFace() const
	{
		return face;
	}

void card::setFace(Value face)
	{
		this->face = face;
	}

card::Suit card::getSuit() const
	{
		return suit;
	}

	void card::setSuit(Suit suit)
	{
		this->suit = suit;
	}

	card::card(int suit, int val)
	{
		if ((suit < 5) && (val < 14)) {
		this->suit = (Suit)suit;
		this->face = (Value)val;
		}
	}

	card::card(const card& base)
	{
		this->suit = base.suit;
		this->face = base.face;
	}

    ostream& operator << (ostream& ostr, card card)
	{
		ostr << card::valStrRep[card.face] << " of " << card::suitStrRep[card.suit] << endl;
		return ostr;
	} // end operator <<

	card operator = (const card& rhs)
	{
		card thisCard(rhs);
		return thisCard;
		//should this return a card or a card's address?
	}


#endif /* CARD_H_ */
