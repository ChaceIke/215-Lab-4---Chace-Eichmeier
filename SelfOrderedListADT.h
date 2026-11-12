/*
 * File:   SelfOrderedListADT.hpp
 * Author: Prof Sipantzi
 *
 * Created on September 28, 2012, 8:18 AM
 * Modified 05/12/2025 -- Prof Sipantzi
 * Modified 05/04/2026 -- Prof Sipantzi
 */

#pragma once

template <class E>
class SelfOrderedListADT {
public:
	//Default constructor/destructor
	SelfOrderedListADT() {}
	virtual ~SelfOrderedListADT() {}

	//Look for 'it'.  If found return true and execute the self-ordering
	//heuristic used for ordering the list: count, move-to-front, or transpose.
	//Increments the compare instance variable every time it compares 'it' to
	//other members of the list. Returns true if 'it' is found.
	virtual bool search(const E& it) = 0;

	//Called by find if 'it' is not in the list. Adds the new 'it' to the list
	//Can also be called independently when initially loading the list with
	//unique values and when you want to load the list in the order 'it' is 
	//read without your re-order method being called (or the number of compares
	//being incremented.
	virtual void addIt(const E& it) = 0;  //Add new 'it' to the list


	virtual int getCompares() const = 0;   //Returns the number of accumulated compares
	virtual int size() const = 0;       //Returns the size of the list

	//Print the list
	//In order print of the list.  printlist() prints the entire list
	//whereas printlist(n) prints n nodes.
	virtual void printlist() const = 0;
	virtual void printlist(int n) const = 0;

private:
	//Protect the copy constructor and assignment operator
	SelfOrderedListADT(const SelfOrderedListADT&) {}
	SelfOrderedListADT operator=(const SelfOrderedListADT&) {}


	// do not make any changes to this file or you will not get
	// any credit for your work -- Prof Sipantzi (11/30/2023)	

};



