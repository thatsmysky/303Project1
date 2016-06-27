//
//  polynomial.cpp
//

#include "polynomial.hpp"
using namespace std;

void sort(list<Term> &poly);
~polynomal();
friend operator+ (const polynomial& other);
friend ostream &operator<<(ostream &out, polynomial& poly);
friend istream &operator>>(istream &in, polynomial& poly);
