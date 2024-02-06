#include <iostream>
#include <string>
using namespace std;
#include "ComputerShop.h"

int main() {
    ComputerShop shop;

    // Main parts chosen from these categories
    string mainCategories[] = {"Case", "RAM", "Main HDD"};
    shop.orderItems(mainCategories, 3);

    char choice;
    bool isValid = false;
    while (!isValid) {
        cout << "\nDo you want to choose additional components? (y/n): ";
        cin >> choice;

        // Clear the cin buffer to avoid while loop from running multiple times when wrong input is entered
        cin.clear(); 
        // ignore upto a theoretical max of 10,000 characters
        cin.ignore(10000, '\n');


        if (choice == 'y' || choice == 'Y') {
            cout << "\nChoose additional components:" << endl;
            // Aditional items chosen from these categories
            string additionalCategories[] = {"SSD", "Second HDD", "Optical Drive", "Operating System"};
            shop.orderItems(additionalCategories, 4);
            isValid = true;
        }
        else if (choice == 'n' || choice == 'N') {
            // Break from while loop
            isValid = true;
        }
        else {
            // Invalid input
            cout << "Invalid input. Try again." << endl;
        }
    }

    // Display final order placed
    shop.displayOrderSummary();

    return 0;
}
