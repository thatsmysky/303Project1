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
public:
    polynomial() {poly.assign(1, 0);};
    polynomial(Term t) {poly.assign(1, t););
    ~polynomal();
    polynomial operator+ (const polynomial& other);
private:
    list<Term> poly;
};