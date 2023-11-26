#include <iostream>
using namespace std;
#include "Shapes.h"

int main() {
    Hexagon hex;
    Square sq;
    int choice;

    do {
        cout << "Enter 1 to calculate area, perimeter, and sum of angles of hexagon" << endl;
        cout << "Enter 2 to calculate area and perimeter of square" << endl;
        cout << "Press any other key to exit" << endl;

        cin >> choice;

        if (choice == 1) {
            hex.display();
        } else if (choice == 2) {
            sq.display();
        }

    } while (choice == 1 || choice == 2);

    cout << "Program exited!" << endl;
    return 0;
}
