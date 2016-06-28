// 303 Project 1B
// June 28th, 2016
// John Buckley

// User menu and main

#include "polynomial.h"
#include "Term.h"
#include <iostream>
#include <list>
using namespace std;

// return whether the menu was processed correctly
bool processMenu(polynomial &polynomial1, polynomial &polynomial2, polynomial &finalPoly) {
    
    // show the main user the menu
    cout << "Polynomial Adder" << endl;
    cout << "(1) Enter Polynomials" << endl;
    cout << "(2) Add Polynomials" << endl;
    cout << "(3) Exit" << endl;
    cout << "Please Enter a Number: ";
    
    // response variables for varius menu inputs
    char choice1, exit1, exit2;
    int polycoef, polyexp;
    Term temp;
    bool loopy = false;
    cin >> choice1;
    
    // user choice 1
    // enter polynomial 1 and 2, force user to enter coefficents and exponents
    if (choice1=='1') {
        cout << "First polynomial " << endl;
        while (loopy != true){ // bool for menu options, loop until user enters n or N
            cout << "Enter a coefficent: ";
            cin >> polycoef;
            cout << "Enter an exponent: ";
            cin >> polyexp;
            
            // use coefficent and exponents to create term and add term to polynomial
            temp = Term(polycoef, polyexp);
            polynomial temp1 = polynomial(temp);
            polynomial1 = polynomial1 + temp1;
            
            cout << "Enter another term in the polynomial? " << endl;
            cout << "(Y)es" << endl;
            cout << "(N)o" << endl;
            cout << "Please enter Y or N: ";
            
            cin >> exit1;
            
            if (exit1 == 'y' || exit1 == 'Y'){
                loopy = false;
            } else if (exit1 == 'n' || exit1 == 'N'){
                loopy = true;
            } else {
                loopy = true;
            } }
        
        // after user enters n or N, user enters coefficents and exponents for second polynomial
        loopy = false;
        cout << "Second Polynomial " << endl;
        while (loopy != true){ // bool for menu options, loop until user enters n or N
            cout << "Enter a coefficent: ";
            cin >> polycoef;
            cout << "Enter an exponent: ";
            cin >> polyexp;
            
            // use coefficent and exponents to create term and add term to polynomial
            temp = Term(polycoef, polyexp);
            polynomial temp2 = polynomial(temp);
            polynomial2 = polynomial2 + temp2;
            
            cout << "Enter another term in the polynomial? " << endl;
            cout << "(Y)es" << endl;
            cout << "(N)o" << endl;
            cout << "Please enter Y or N: ";
            
            cin >> exit2;
            
            if (exit2 == 'y' || exit2 == 'Y'){
                loopy = false;
            } else if (exit2 == 'n' || exit2 == 'N'){
                loopy = true;
            } else {
                loopy = true;
            } }
        
        return false; // back to main menu
        
        // user choice 2
        // adds polynomial1 and polynomial2, stores value in polynomial called finalPoly, displays finalPoly
        // also clears polynomial1, polynomial2, and finalPoly so user can add as many polynomials as they want
    } else if (choice1=='2') {
        cout << "Adding polynomials" << endl;
        finalPoly = polynomial1 + polynomial2;
        cout << "The result is: " << finalPoly << endl;
        
        //Clear polys
        polynomial1.clear();
        polynomial2.clear();
        finalPoly.clear();
        
        system("Pause");
        return false; // return to main menu
        
        // user choice 3
        // exit user menu and program
    } else if (choice1=='3') {
       
        // Creates list that displays exit prompt
        // uses iterator to go through list
        list <string> listy;
        listy.push_back("Now");
        listy.push_back("Exiting");
        listy.push_back("Program");
        for(list<string>::const_iterator requiredIter = listy.begin(), end=listy.end(); requiredIter != end; ++requiredIter){
            cout << *requiredIter + " ";
        }
        
        // if any other user input is entered, give error message and redisplay main menu options
    } else {
        cout << "Your input was not valid, please try again." << endl;
        return false;
    }
    
    return true; // Exit menu and program
    
}

int main () {
    
    // polynomials used for edition
    polynomial polynomial1, polynomial2, finalPoly;
    
    // loop until the menu is processed / user is finished
    while (!processMenu(polynomial1, polynomial2, finalPoly)) {
    }
    
    system("Pause");
    return 0;
}