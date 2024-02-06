#include <iostream>
using namespace std;

// constants to hold 2D array size
const int SLAB_COUNT = 3;
const int SLAB_ENTRIES = 3;

// Function prototypes
void costSlab1(int matrix[SLAB_COUNT][SLAB_ENTRIES]);
void costSlab2(int matrix[SLAB_COUNT][SLAB_ENTRIES]);
void costSlab3(int matrix[SLAB_COUNT][SLAB_ENTRIES]);
int calculateBill(int units, int rate);

int main() {
    // Student ID and Matrix data
    string studentID;
    int matrix[SLAB_COUNT][SLAB_ENTRIES] = {
        {55, 65, 75},   
        {120, 150, 170}, 
        {210, 230, 240}  
    };

    // taking user input for student ID
    cout << "Enter your student ID: ";
    cin >> studentID;
    cout << endl;

    char choice;
    // taking user input for choice
    do {
        cout << "My Student ID is " << studentID << endl;
        cout << "Enter your choice" << endl;
        cout << "Press 1 to display the bill of slab 1 and slab 2." << endl;
        cout << "Press 2 to display the bill of slab 3." << endl;
        cout << "Press any other key to exit." << endl;
        cin >> choice;

        switch (choice) {
            case '1':
                costSlab1(matrix);
                cout << endl;
                costSlab2(matrix);
                cout << "\n\n" << endl;
                break;
            case '2':
                costSlab3(matrix);
                cout << "\n\n" << endl;
                break;
            default:
                // Terminate the program
                cout << "Exiting program." << endl;
                return 0; 
        }
    } while (true);

    return 0;
}
// Functions to calculate slab prices
void costSlab1(int matrix[SLAB_COUNT][SLAB_ENTRIES]) {
    cout << "Bill for Slab 1 is ";
    for (int i = 0; i < SLAB_ENTRIES; ++i) {
        cout << calculateBill(matrix[0][i], 10) << " ";
    }
    cout << endl;
}

void costSlab2(int matrix[SLAB_COUNT][SLAB_ENTRIES]) {
    cout << "Bill for Slab 2 is ";
    for (int i = 0; i < SLAB_ENTRIES; ++i) {
        cout << calculateBill(matrix[1][i], 15) << " ";
    }
    cout << endl;
}

void costSlab3(int matrix[SLAB_COUNT][SLAB_ENTRIES]) {
    cout << "Bill for Slab 3 is ";
    for (int i = 0; i < SLAB_ENTRIES; ++i) {
        cout << calculateBill(matrix[2][i], 20) << " ";
    }
    cout << endl;
}


int calculateBill(int units, int rate) {
    return units * rate;
}
