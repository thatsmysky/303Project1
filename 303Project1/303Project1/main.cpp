// 303 Project 1
// user menu and main

#include "polynomial.hpp"
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
    
    // response variables
    char choice1, exit1, exit2;
    int polycoef, polyexp;
    Term temp;
    bool loopy = false;
    cin >> choice1;
    
    // enter polynomials, displays user entered polynomials for review
    // if user input correct return to main menu, if incorrect allow user to reenter polynomials
    if (choice1=='1') {
        cout << "Enter first polynomial: ";
        while (loopy != true){ // bool for menu options
            cout << "Enter a coefficent: " << endl;
            cin >> polycoef;
            cout << "Enter an exponent: " << endl;
            cin >> polyexp;
            
            temp = Term(polycoef, polyexp);
            polynomial temp1 = polynomial(temp);
            polynomial1 = polynomial1 + temp1;
            
            cout << "Enter another term in the polynomial? ";
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
        
        
        loopy = true;
        cout << "Enter second polynomial: ";
        while (loopy != true){ // bool for menu options
            cout << "Enter a coefficent: " << endl;
            cin >> polycoef;
            cout << "Enter an exponent: " << endl;
            cin >> polyexp;
            
            temp = Term(polycoef, polyexp);
            
            polynomial temp2 = polynomial(temp);
            polynomial2 = polynomial2 + temp2;
            
            cout << "Enter another term in the polynomial? ";
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
        return false;
        
        // adds both polynomials and displays result
    } else if (choice1=='2') {
        cout << "Adding polynomials" << endl;
        finalPoly = polynomial1 + polynomial2;
        cout << "The result is: " << finalPoly << endl;
        
        // exit command
    } else if (choice1=='3') {
        cout << "Now Exiting Program." << endl;
        
        // if any other user input is entered, give error message and redisplay main menu options
    } else {
        cout << "Your input was not valid, please try again." << endl;
        return false;
    }
    
    return true;
    
}

int main () {
        
    // strings to hold polynomials to be added and sum
    polynomial polynomial1, polynomial2, finalPoly;
    
    // loop until the menu is processed or user is finished
    while (!processMenu(polynomial1, polynomial2, finalPoly)) {
    }
    
    
    return 0;
}
