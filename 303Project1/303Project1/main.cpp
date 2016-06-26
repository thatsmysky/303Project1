// 303 Project 1
// user menu and main

#include <iostream>
#include <list>
using namespace std;

// return whether the menu was processed correctly
bool processMenu(string polynomial1, string polynomial2, int sum) {
    
    // show the main user the menu
    cout << "Polynomial Adder" << endl;
    cout << "(1) Enter Polynomials" << endl;
    cout << "(2) Add Polynomials" << endl;
    cout << "(3) Exit" << endl;
    cout << "Please Enter a Number: ";
    
    // response variables
    char choice1, choice2;
    cin >> choice1;
    
    // enter polynomials, displays user entered polynomials for review
    // if user input correct return to main menu, if incorrect allow user to reenter polynomials
    if (choice1=='1') {
        cout << "Enter first polynomial: ";
        cin >> polynomial1;
        cout << "Enter second polynomial: ";
        cin >> polynomial2;
        cout << "You entered: " + polynomial1 + " and " + polynomial2 << endl;
        cout << " Is this correct?" << endl;
        cout << "(1) Yes" << endl;
        cout << "(2) No" << endl;
        cout << "Please Enter a number: ";
        cin >> choice2;
        
        while (choice2 != '1'){
            if(choice2=='2'){
                cout << "Enter first polynomial: ";
                cin >> polynomial1;
                cout << "Enter second polynomial: ";
                cin >> polynomial2;
                cout << "You entered: " + polynomial1 + " and " + polynomial2;
                cout << " Is this correct?" << endl;
                cout << "(1) Yes" << endl;
                cout << "(2) No" << endl;
                cout << "Please Enter a number: ";
                cin >> choice2;
    } else {
        cout << "Your input was not valid, returning to main menu." << endl;
        choice2 = '1';
        }
    }
        
    if(choice2=='1'){
        cout << "Your input was saved, returning to main menu." << endl;
        return false;
    }
return false;
        
    // adds both polynomials and displays result
    } else if (choice1=='2') {
        cout << "Adding variables" << endl;
        sum = 1;
   
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
    string polynomial1, polynomial2;
    int sum;
    
    // loop until the menu is processed or user is finished
    while (!processMenu(polynomial1, polynomial2, sum)) {
    }
    
    return 0;
}