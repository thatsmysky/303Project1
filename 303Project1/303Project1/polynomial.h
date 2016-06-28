//
//  polynomial.hpp
//  a polynomial is a linked list of Terms
//  Term -> Term -> Term
//  x^2 -> 2x -> 4
//
//  this class must:
//  create a polynomial
//  add polynomials
//  destroy polynomails
//
//  Created by Lucicle on 6/26/16.
//
//

#pragma once

#include <iostream>
#include "Term.h"
#include <list>
using namespace std;

class polynomial
{
private:
    list<Term> poly;
    Term newTerm;
    
public:
    polynomial() {poly.push_front(newTerm);};
    polynomial(Term t) {poly.assign(1, t);};
    ~polynomial();
    list<Term> operator+ (list<Term> &other);
    friend ostream &operator<<(ostream &out, list<Term> &poly);
};

