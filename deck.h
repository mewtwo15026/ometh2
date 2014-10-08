/*
 * deck.h
 *
 *  Created on: Oct 1, 2014
 *      Author: sean
 */

#ifndef DECK_H_
#define DECK_H_

#include "card.h"
#include "d_node.h"

using namespace std;


class deck {
private:
	node<card> *head;
public:
	//TODO add destructor which traverses the nodes, deleting each of them
	//TODO deal, which removes the top card from the deck and returns it
	//TODO add replace function, which puts a card on the bottom of the deck
	//     replace needs to be able to handle (head == NULL)
	//TODO add shuffle which shuffles the given deck
	deck(){
		node<card> *old = NULL;
		node<card> *current = NULL;
		for (int suit = 3; suit >= 0; suit--) {
			for (int face = 12; face >= 0; face--) {
				if (current == NULL){
					current = new node<card>(card(suit, face));
				} else {
					old = current;
					current = new node<card>(card(suit,face), old);
				} // end ifelse
			} // end for
		} // end for
		head = current;
	} // end constructor

	~deck()
	{
		node<card> *newHead;

		while(head != NULL)
		{
			newHead = head->next;
			delete head;
			head = newHead;
		}
	}

	friend ostream& operator << (ostream& ostr, deck& deck)
	{
		node<card> *car = deck.head;
		while(car != NULL)
		{
			ostr << car->nodeValue << endl;
			car = car->next;
		}
	return ostr;
	} // end operator <<
	
	card deal()
	{
		card dealtCard = head->nodeValue;
		node<card> *newHead = head->next;
		delete head;
		head = newHead;
		return dealtCard;
	}

	void replace(card toReplace)
	{
		node<card> *bottomCard(toReplace, NULL);
		node<card> *tempNode = head;
		while(tempNode->next != NULL)
		{
			tempNode = tempNode->next;
		}
		tempNode->next = bottomCard;
	}
};



#endif /* DECK_H_ */
