/*
 * deck.h
 *
 *  Created on: Oct 1, 2014
 *      Author: sean
 */

#ifndef DECK_H_
#define DECK_H_

#include"card.h";
#include "d_node.h";

using namespace std;


class deck {
private:
	node<card> *head;
public:
	deck(){
		//TODO find and replace nullptr with NULL before submitting
		node<card> *old;
		node<card> *current;
		for (int suit = 3; suit >= 0; suit--) {
			for (int face = 13; face >= 0; face--) {
				if (old == NULL){
					current = new node<card>(card(suit, face));
				} else {
					old = current;
					current = new node<card>(card(suit,face), old);
				} // end ifelse
			} // end for
		} // end for
		head = current;
	} // end constructor

	friend ostream& operator << (ostream& ostr, card& card)
	{
		node<card> *car = head;
		while(head != NULL)
		{
			ostr << *car << endl;
			car = car->next;
		}
		return ostr;
	} // end operator <<

};



#endif /* DECK_H_ */
