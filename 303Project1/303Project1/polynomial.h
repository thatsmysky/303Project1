//
//  polynomial.h
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
    Term *head = new Term;
    
    //default constructor
    polynomial();
    
    //suplemental constructor just in case
    polynomial(Term t);
    
    //push back a Term onto the list of terms
    void push_back(Term &t);
        
    //overloaded assignment opperator
    polynomial operator+ (polynomial &other);
        
    //overloaded output stream
    friend ostream &operator<<(ostream &out, polynomial &poly);
    
    //clear function for cleaning
    void clear(polynomial &p);

};

