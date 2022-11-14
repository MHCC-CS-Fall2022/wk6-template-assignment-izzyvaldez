/*
 wk6_Template_Class_ivaldez.cxx
 Summary:        Demonstrate the implementation of a template class.
 Specifications: Program will use template headers to run the program, using functions from the
                 bag class and node class to run template functions.
 Test cases:     Positive integers entered through the get_ages() function and check_ages() function.
 Author:         Isaias Valdez
 Created:        November 8, 2022
 Summary of Modifications:
 */

#include <iostream>     // Provides cout and cin
#include <cstdlib>      // Provides EXIT_SUCCESS
#include "Tbag.h"       // With Item defined as an int
using namespace std;
using namespace main_savitch_5;

// PROTOTYPES for functions used by this demonstration program:
void get_ages(bag<int>& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members. These ages have been read and placed in the ages bag, stopping
// when the user types a negative number.

void check_ages(bag<int>& ages);
// Postcondition: The user has been prompted to type in the ages of family
// members once again. Each age is removed from the ages bag when it is typed,
// stopping when the bag is empty.


int main( )
{
    bag<int> ages;

    get_ages(ages);
    check_ages(ages);
    cout << "May your family live long and prosper." << endl;
    return EXIT_SUCCESS;
}


void get_ages(bag<int>& ages)
{
    int user_input; // An age from the user's family

    cout << "Type the ages in your family. ";
    cout << "Type a negative number when you are done:" << endl;
    cin >> user_input;
    while (user_input >= 0)
    {
        ages.insert(user_input);
        cin >> user_input;
    }
}

void check_ages(bag<int>& ages)
{
    int user_input; // An age from the user's family

    cout << "Type those ages again. Press return after each age:" << endl;
    while (ages.size( ) > 0)
    {
        cin >> user_input;
        if (ages.erase_one(user_input))
            cout << "Yes, I've got that age and have removed it." << endl;
        else
            cout << "No, that age does not occur!" << endl;
    }
}
