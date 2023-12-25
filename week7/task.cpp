#include <iostream>
#include <string>
using namespace std;

const int NUM_CHARITIES = 3;

// Function declarations
void setupCharitySystem(string charities[], double donations[]);
int getCharityChoice();
double getShoppingBill();
void recordDonation(const string charities[], double donations[], int choice, double bill);
void displayTotals(const string charities[], const double donations[]);
void displayDescendingOrder(const string charities[], const double donations[]);

int main() {
    string charities[NUM_CHARITIES];
    double donations[NUM_CHARITIES] = {0};
    int charityChoice;
    double shoppingBill;

    setupCharitySystem(charities, donations);

    while (true) {
        charityChoice = getCharityChoice();
        
        if (charityChoice == -1) {
            displayDescendingOrder(charities, donations);
            break;
        }

        shoppingBill = getShoppingBill();
        recordDonation(charities, donations, charityChoice, shoppingBill);
    }

    return 0;
}

void setupCharitySystem(string charities[], double donations[]) {
    cout << "Enter the names of three charities:\n";
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << "Charity " << (i + 1) << ": ";
        getline(cin, charities[i]);
        donations[i] = 0; // Initialize donation total
    }
}

int getCharityChoice() {
    int choice;
    cout << "\nChoose a charity (1, 2, 3) or -1 to show totals: ";
    cin >> choice;
    if ((choice < 1 || choice > 3) && choice != -1) {
        cout << "Invalid choice. Please choose 1, 2, 3, or -1.\n";
        return getCharityChoice(); // Recursive call for valid input
    }
    return choice;
}

double getShoppingBill() {
    double bill;
    cout << "Enter the value of the customer's shopping bill: ";
    cin >> bill;
    return bill;
}

void recordDonation(const string charities[], double donations[], int choice, double bill) {
    double donation = bill * 0.01; // 1% donation
    donations[choice - 1] += donation;
    cout << "Donated $" << donation << " to " << charities[choice - 1] << ".\n";
}

void displayTotals(const string charities[], const double donations[]) {
    double grandTotal = 0;
    cout << "\nGRAND TOTAL DONATED TO CHARITY:\n";
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << charities[i] << ": $" << donations[i] << "\n";
        grandTotal += donations[i];
    }
    cout << "Total: $" << grandTotal << "\n";
}

void displayDescendingOrder(const string charities[], const double donations[]) {
    // Assuming a simple selection sort for descending order
    int indices[NUM_CHARITIES] = {0, 1, 2};
    for (int i = 0; i < NUM_CHARITIES - 1; i++) {
        for (int j = i + 1; j < NUM_CHARITIES; j++) {
            if (donations[indices[i]] < donations[indices[j]]) {
                swap(indices[i], indices[j]);
            }
        }
    }

    double grandTotal = 0;
    cout << "\nCharities in Descending Order of Donations:\n";
    for (int i = 0; i < NUM_CHARITIES; ++i) {
        cout << charities[indices[i]] << ": $" << donations[indices[i]] << "\n";
        grandTotal += donations[indices[i]];
    }
    cout << "GRAND TOTAL DONATED TO CHARITY: $" << grandTotal << "\n";
}
