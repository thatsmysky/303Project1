#pragma once
//Term for nodes of linked-list for polynomial representation

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

using namespace std;

//   One Term within a Polynomial
class Term
{
	friend bool operator<(const Term& lhs, const Term& rhs); //for comparing lhs < rhs exponents
	friend ostream& operator<<(ostream& ostr, Term& term);		//for outputting the Term to cout

private:
	int coe, exp;        // data - coefficient and exponent
	

public:


	Term();		//default constructor
	Term(int coe, int exp);		//regular constructor
	
	Term* next;  // link to next Term 
	
	int getCoe();
	int getExp();

	void setCoe(int coe);
	void setExp(int exp);

};