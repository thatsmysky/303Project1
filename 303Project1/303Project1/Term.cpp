//Term for nodes of linked-list for polynomial representation

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>

#include "Term.h"

using namespace std;

//   One Term within a Polynomial

bool operator<(const Term& lhs, const Term& rhs) {		//compares lhs < rhs exponents
	if (lhs.exp < rhs.exp) return true;
	return false;
}

bool operator>(const Term& lhs, const Term& rhs) {		//compares lhs > rhs exponents
	if (lhs.exp > rhs.exp) return true;
	return false;
}

bool operator==(const Term& lhs, const Term& rhs) {		//compares lhs == rhs exponents
	if (lhs.exp == rhs.exp) return true;
	return false;
}

ostream& operator<<(ostream& ostr, Term& term) {		//for outputting Term to cout
	if (term.coe == 0) return ostr << "";		//do not display terms with 0 coefficients
	
	return ostr << term.coe << "x^" << term.exp << " ";		//outputs "_x^_ "
	//remember to remove - sign and change + to - for negative numbers on polynomial output
}


Term::Term() {		//default constructor
	coe = 0;
	exp = 0;
}

Term::Term(int arg1, int arg2) {		//regular constructor
	coe = arg1;
	exp = arg2;
}

int Term::getCoe() {
	return coe;
}

int Term::getExp(){
	return exp;
}

void Term::setCoe(int arg) {
	coe = arg;
}

void Term::setExp(int arg) {
	exp = arg;
}



