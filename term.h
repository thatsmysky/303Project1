//  Jeremy Culbreath
//  CS303 Project 1B
//  term.h
//  6/28/16
//
//Term for nodes of linked-list for polynomial representation

#pragma once

#include <iostream>
#include <string>
using namespace std;

//   One Term within a Polynomial
class Term
{
	friend bool operator<(const Term& lhs, const Term& rhs);	//for comparing lhs < rhs exponents
	friend bool operator>(const Term& lhs, const Term& rhs);	//for comparing lhs > rhs exponents
	friend bool operator==(const Term& lhs, const Term& rhs);	//for comparing lhs == rhs exponents
	friend ostream& operator<<(ostream& ostr, Term& term);		//for outputting the Term to cout

private:
	//none

public:
	int coe, exp;					// data - coefficient and exponent


	Term();							//default constructor
	Term(int coe, int exp);			//regular constructor
	
	Term* next;						// link to next Term 
	
	int getCoe();
	int getExp();

	void setCoe(int coe);
	void setExp(int exp);

};
