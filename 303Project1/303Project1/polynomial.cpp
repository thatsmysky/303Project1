//
//  polynomial.cpp
//

#include "polynomial.hpp"
#include <iostream>
using namespace std;


polynomial::polynomial()
{
    head->coe = 0;
    head->exp = 0;
    head->next = NULL;
}

polynomial::polynomial(Term t)
{
    head->setCoe(t.getCoe());
    head->exp = t.getExp();
    head->next = NULL;
}



polynomial polynomial::operator+ (polynomial &other)
{
    polynomial result;
    Term *polyIndex = head;
    Term *otherIndex = other.head;
    while (polyIndex != NULL && otherIndex != NULL)
    {
        if (result.head->getExp() == 0 && result.head->getExp() == 0)
        {
            if (polyIndex->getExp() > otherIndex->getExp())
            {
                result.head->setCoe(polyIndex->getCoe());
                result.head->setExp(polyIndex->getExp());
                polyIndex = polyIndex->next;
            }
            
            else if (polyIndex->getExp() == otherIndex->getExp())
            {
                int buff = polyIndex->getCoe() + otherIndex->getCoe();
                int ffer = polyIndex->getExp();
                result.head->setCoe(buff);
                result.head->setExp(ffer);
                polyIndex = polyIndex->next;
                otherIndex = otherIndex->next;
            }
            
            else
            {
                result.head->setCoe(otherIndex->getCoe());
                result.head->setExp(otherIndex->getExp());
                otherIndex = otherIndex->next;
            }
        }
        
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

ostream &operator<<(ostream &out, polynomial &poly)
{
    for (Term *i = poly.head; i != NULL; i = i->next)
    {
        out << *i;
        if (i->next->next != NULL)
            out<< " + ";
    }
    return out;
}

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
