#include <iostream>
#include <cstdlib> 
#include <ctime>    
#include "ElectricMountainRailway.h"

using namespace std;


int getRandomTickets(int maxSeats) {
    return rand() % maxSeats + 1; // Generates a random number between 1 and maxSeats
}

// Test for ElectricMountainRailway Class
int main() {
    ElectricMountainRailway emr;
    srand(time(0)); // Seed for random number generation

    // Display initial train status
    cout << "Initial Train Status:" << endl;
    emr.displayTrainStatus();
    cout << "\n\n\n\n" << endl;

    // Simulating random ticket purchases for each train
    for (int i = 0; i < 8; ++i) {
        int maxSeats;
        if (i == 7) { // Last train
            maxSeats = 640;
        } else {
            maxSeats = 480;
        }
        
        int ticketsToPurchase = getRandomTickets(maxSeats);
        emr.purchaseTickets(i, ticketsToPurchase);
        cout << "Purchased " << ticketsToPurchase << " tickets for train " << i + 1 << endl;
        cout << "\n" << endl;
    }

    // Display train status after random purchases
    cout << "\nTrain Status After Purchases:" << endl;
    emr.displayTrainStatus();
    cout << "\n\n\n\n" << endl;

    // End of day summary
    cout << "\nEnd of Day Summary:" << endl;
    emr.endOfDaySummary();
    cout << "\n\n\n\n" << endl;

    return 0;
}
