#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ElectricMountainRailway.h"

using namespace std;

int main() {
    ElectricMountainRailway emr;

    int choice, trainIndex, numTickets;
    const string trainTimes[8] = {"09:00 to the mountain", "11:00 to the mountain", "13:00 to the mountain", "15:00 to the mountain", 
                                  "10:00 from the mountain", "12:00 from the mountain", "14:00 from the mountain", "16:00 from the mountain"};

    while (!emr.allSeatsBooked()) {
        cout << "\n\nElectric Mountain Railway Main Menu\n";
        cout << "1. Purchase Tickets\n";
        cout << "2. Display Train Status\n";
        cout << "3. Show End of Day Summary\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Purchase Tickets
                cout << "Select train time:\n";
                for (int i = 0; i < 8; ++i) {
                    cout << i + 1 << ". " << trainTimes[i] << "\n";
                }
                cout << "Enter choice (1 to 8): ";
                cin >> trainIndex;
                trainIndex--; // Adjust for 0-based index

                cout << "Enter number of tickets: ";
                cin >> numTickets;
                emr.purchaseTickets(trainIndex, numTickets);
                break;
            case 2: // Display Train Status
                emr.displayTrainStatus();
                break;
            case 3: // Show End of Day Summary
                emr.endOfDaySummary();
                break;
            case 4: // Exit
                return 0;
            default:
                cout << "Invalid choice. Please try again.";
        }
    }

    cout << "\nAll seats have been sold out!\n";
    emr.endOfDaySummary();

    return 0;
}

