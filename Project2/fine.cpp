// Name: Bonnie Liu
// UID: 005300989
// Class: CS 31 Discussion 1F
// Programming Assignment 2: One Fine Day

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Declaration of Variables
	string name;
	double amountPaid;
	string fake;

	cout << "Defendant: "; // prompts user for defendant name
	getline(cin, name);
	if (name == "") // checks if the variable name takes on an empty string
		cout << "---\nYou must enter a defendant name." << endl;
	else
	{
		cout << "Amount paid (in thousands): "; // prompts user for amount paid
		cin >> amountPaid;
		if (amountPaid < 0) // checks if the variable amountPaid is a negative number
		{
			cout << "---\nThe amount paid must not be negative." << endl;
		}
		else
		{
			cin.ignore(10000, '\n');
			cout << "Fake athlete? (y/n): "; // prompts user for whether or not defendant faked athlete
			getline(cin, fake);
			if ((fake != "y") && (fake != "n")) // checks if user inputted a valid value for the variable fake
			{
				cout << "---\nYou must enter y or n." << endl;
			}
			else
			{
				double fine; // declares the variable fine, which represents the suggested fine
				if (amountPaid <= 40) {
					// Case 1: amount paid was less than or equal to 40
					fine = 20 + amountPaid * 0.66;
				}
				else if (amountPaid <= 250) {
					if (fake == "n") {
						// Case 2: amount paid was between 40 and 250 and athletic achievement was not faked
						fine = 46.4 + (amountPaid - 40) * 0.1;
					}
					else
						// Case 3: amount paid was between 40 and 250 and athletic achievement was faked
						fine = 46.4 + (amountPaid - 40) * 0.22;
				}
				else {
					if (fake == "n") {
						// Case 4: amount paid was greater than 250 and athletic achievement was not faked
						fine = 67.4 + (amountPaid - 250) * (0.14);
					}
					else
						// Case 5: amount paid was greater than 250 and athletic achievement was faked
						fine = 92.6 + (amountPaid - 250) * (0.14);
				}
				// The following formats double outputs so that there is one value after the decimal point.
				cout.setf(ios::fixed);
				cout.precision(1);
				// prints results
				cout << "---\nThe suggested fine for " << name << " is $" << fine << " thousand." << endl;
			}
		}
	}
}