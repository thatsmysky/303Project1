//
//  polynomial.cpp
//

#include "polynomial.hpp"
#include <iostream>
using namespace std;

void polynomial::sort()
{
    
}

polynomial operator+ (const polynomial& other)
{
    other.sort();
}

ostream &operator<<(ostream &out, polynomial& poly)
{
    for (list<Term>::iterator i = poly.begin(); i != poly.end(); i++)
    {
        out << *i;
    }
}


polynomial::~polynomial()
{
    poly.~list();
}
