//
//  polynomial.cpp
//

#include "polynomial.hpp"
#include <iostream>
using namespace std;


list<Term> polynomial::operator+ (list<Term> &other)
{
    list<Term> result;
    list<Term>::iterator polyIndex = poly.begin();
    list<Term>::iterator otherIndex = other.begin();
    while (polyIndex != poly.end() && otherIndex != other.end())
    {
        if (polyIndex->getExp() > otherIndex->getExp())
        {
            result.push_back(*polyIndex);
            polyIndex++;
        }
        
        else if (polyIndex->getExp() == otherIndex->getExp())
        {
            int buff = polyIndex->getCoe() + otherIndex->getCoe();
            int ffer = polyIndex->getExp();
            Term dummy = Term(buff, ffer);
            result.push_back(dummy);
        }
        
        else
        {
            result.push_back(*otherIndex);
            otherIndex++;
        }
    }
    return result;
}

ostream &operator<<(ostream &out, list<Term> &poly)
{
    for (list<Term>::iterator i = poly.begin(); i != poly.end(); i++)
    {
        out << *i;
    }
    return out;
}


polynomial::~polynomial()
{
    poly.~list();
}
