//  Lucy Kull
//  polynomial.cpp
//

#include "polynomial.h"
#include <iostream>
using namespace std;

//default constructor//

polynomial::polynomial()
{
    //initialize everything to 0/NULL
    head->coe = 0;
    head->exp = 0;
    head->next = NULL;
}

//secondary constructor//

polynomial::polynomial(Term t)
{
    //initializes polynomial to Term specifications
    head->setCoe(t.getCoe());
    head->exp = t.getExp();
    head->next = NULL;
}


//overloaded addition operator//

polynomial polynomial::operator+ (polynomial &other)
{
    polynomial result;  //output vairable
    Term *polyIndex = head;  //lhs variable
    Term *otherIndex = other.head;  //rhs variable
    while (polyIndex != NULL && otherIndex != NULL) //while both polynomials exist
    {
        if (result.head->getExp() == 0 && result.head->getExp() == 0) //if the result is initialized and 'empty'
        {
            if (polyIndex->getExp() > otherIndex->getExp()) //lhs exponent > rhs exponent
            {
                result.head->setCoe(polyIndex->getCoe());
                result.head->setExp(polyIndex->getExp());
                polyIndex = polyIndex->next;
            }
            
            else if (polyIndex->getExp() == otherIndex->getExp()) //lhs exponent = rhs exponent
            {
                int buff = polyIndex->getCoe() + otherIndex->getCoe(); //add coefs
                int ffer = polyIndex->getExp();
                result.head->setCoe(buff);
                result.head->setExp(ffer);
                polyIndex = polyIndex->next;
                otherIndex = otherIndex->next;
            }
            
            else //rhs exponent > lhs exponent
            {
                result.head->setCoe(otherIndex->getCoe());
                result.head->setExp(otherIndex->getExp());
                otherIndex = otherIndex->next;
            }
        }
        
        //one polynomial is empty and the other is not:
        
        if ((polyIndex != NULL && otherIndex != NULL) &&(polyIndex->getExp() > otherIndex->getExp()))
        {
            result.push_back(*polyIndex);
            polyIndex = polyIndex->next;
        }
        
        else if ((polyIndex != NULL && otherIndex != NULL) && (polyIndex->getExp() == otherIndex->getExp()))
        {
            int buff = polyIndex->getCoe() + otherIndex->getCoe();
            int ffer = polyIndex->getExp();
            Term dummy = Term(buff, ffer);
            result.push_back(dummy);
            polyIndex = polyIndex->next;
            otherIndex = otherIndex->next;
        }
        
        else if (polyIndex != NULL && otherIndex != NULL)
        {
            result.push_back(*otherIndex);
            otherIndex = otherIndex->next;
        }
    }
    
    while (polyIndex == NULL && otherIndex != NULL)
    {
        result.push_back(*otherIndex);
        otherIndex = otherIndex -> next;
    }
    
    while (polyIndex != NULL && otherIndex == NULL)
    {
        result.push_back(*polyIndex);
        polyIndex = polyIndex -> next;
    }
    return result;
}


//overloaded output operator//

ostream &operator<<(ostream &out, polynomial &poly)
{
    //iterates through the list and outputs the term as needed
    Term *i = poly.head;
    do
    {
        out << *i;
        if (i->next != NULL && i->next->coe > 0 && i->coe != 0)
            out << "+ ";
        else if (i->next != NULL && i->next->coe < 0)
            out << "- ";
        i = i->next;
    }while(i);
    return out;
}

//overloaded push-back operator//

void polynomial::push_back(Term &t)
{
    Term *newTerm = new Term;
    newTerm->coe = t.coe;
    newTerm->exp = t.exp;
    newTerm->next = NULL;
    
    Term *curr = head;
    while(curr)
    {
        if (curr->next == NULL)
        {
            curr->next = newTerm;
            return;
        }
        curr = curr->next;
    }
}


//clear function for clearing//

void polynomial::clear()
{
    Term *temp;
    while (head)
    {
        temp = head;
        head = temp->next;
        delete temp;
    }
}
