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
	if (abs(term.coe) != 1); ostr << abs(term.coe);	//polynomial class ostream should look at - and makes + into -
	if (term.exp != 0) ostr << "x";				//don not display x for 0 exponents
	if (term.exp != 0 && term.exp != 1) ostr << "^" << term.exp;		//do not display ^ and exponent for 0 or 1 exponets
	ostr << " ";		//space before next term
	return ostr;		//outputs "_x^_ "
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



