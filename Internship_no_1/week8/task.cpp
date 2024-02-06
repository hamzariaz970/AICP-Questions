#include <iostream>
#include <algorithm>
using namespace std;

struct Boat {
    int number;
    bool isHired;
    int returnTime; // Represented in 24-hour format
    double totalHoursHired;
    double dailyEarnings;

    Boat() : number(0), isHired(false), returnTime(1000), totalHoursHired(0), dailyEarnings(0.0) {}
};

// Function declarations
void hireBoat(Boat& boat);
void findNextAvailableBoat(Boat boats[], int numBoats);
void endOfDayReport(Boat boats[], int numBoats);

const int NUM_BOATS = 10;
const int OPEN_TIME = 1000;
const int CLOSE_TIME = 1700;
const double FULL_HOUR_RATE = 20.0;
const double HALF_HOUR_RATE = 12.0;


// Task 1 - Function to hire boat
void hireBoat(Boat& boat) {
    int currentTime, duration;
    cout << "Enter current time (HHMM): ";
    cin >> currentTime;
    if (currentTime < OPEN_TIME || currentTime >= CLOSE_TIME) {
        cout << "Boat hiring is closed now. Please come back between 10:00 and 17:00.\n";
        return;
    }

    cout << "Enter hire duration (1 for half an hour, 2 for one hour): ";
    cin >> duration;
    if (duration != 1 && duration != 2) {
        cout << "Invalid duration. Only 1 or 2 hours are allowed.\n";
        return;
    }

    boat.isHired = true;
    boat.returnTime = currentTime + (duration == 1 ? 30 : 100);
    boat.totalHoursHired += duration;
    boat.dailyEarnings += (duration == 1 ? HALF_HOUR_RATE : FULL_HOUR_RATE);
    cout << "Boat " << boat.number << " hired. Return by " << boat.returnTime << ".\n";
}

// Task 2 - Function for finding next available boat
void findNextAvailableBoat(Boat boats[], int numBoats) {
    int earliestReturn = CLOSE_TIME;
    bool allHired = true;

    for (int i = 0; i < numBoats; i++) {
        if (!boats[i].isHired) {
            cout << "Boat " << boats[i].number << " is available for hire now.\n";
            allHired = false;
            break;
        } else if (boats[i].returnTime < earliestReturn) {
            earliestReturn = boats[i].returnTime;
        }
    }

    if (allHired) {
        cout << "No boats are available right now. The earliest available time is " << earliestReturn << ".\n";
    }
}

// Task 3 - Function to generate end of day report
void endOfDayReport(Boat boats[], int numBoats) {
    double totalEarnings = 0;
    int totalHours = 0, unusedBoats = 0, mostUsedBoat = 0, maxHours = 0;

    for (int i = 0; i < numBoats; ++i) {
        const Boat& boat = boats[i];  // Access each boat from the array
        totalEarnings += boat.dailyEarnings;
        totalHours += boat.totalHoursHired;

        if (boat.totalHoursHired == 0) {
            unusedBoats++;
        }

        if (boat.totalHoursHired > maxHours) {
            maxHours = boat.totalHoursHired;
            mostUsedBoat = boat.number;
        }
    }

    cout << "\nEnd of Day Report:\n";
    cout << "Total Earnings: $" << totalEarnings << "\n";
    cout << "Total Hours Hired: " << totalHours << "\n";
    cout << "Number of Unused Boats: " << unusedBoats << "\n";
    cout << "Most Used Boat: Boat " << mostUsedBoat << "\n";
}


int main() {

    Boat boats[NUM_BOATS];
    for (int i = 0; i < NUM_BOATS; ++i) {
        boats[i].number = i + 1;
    }

    // Simulating the hiring of boats throughout the day
    // Boat 1 hired for 1 hour at 10:15
    boats[0].isHired = true;
    boats[0].returnTime = 1115;
    boats[0].totalHoursHired = 1;
    boats[0].dailyEarnings = FULL_HOUR_RATE;

    // Boat 2 hired for half an hour at 10:30
    boats[1].isHired = true;
    boats[1].returnTime = 1100;
    boats[1].totalHoursHired = 0.5;
    boats[1].dailyEarnings = HALF_HOUR_RATE;

    // Boat 3 hired for 1 hour at 11:00
    boats[2].isHired = true;
    boats[2].returnTime = 1200;
    boats[2].totalHoursHired = 1;
    boats[2].dailyEarnings = FULL_HOUR_RATE;

    // Boat 4 hired for half an hour at 12:30
    boats[3].isHired = true;
    boats[3].returnTime = 1300;
    boats[3].totalHoursHired = 0.5;
    boats[3].dailyEarnings = HALF_HOUR_RATE;

    // Check for the next available boat after boat 2 returns
    cout << "Checking for next available boat at 11:00:\n";
    findNextAvailableBoat(boats, NUM_BOATS);

    // Boat 5 hired for 1 hour at 13:00
    boats[4].isHired = true;
    boats[4].returnTime = 1400;
    boats[4].totalHoursHired = 1;
    boats[4].dailyEarnings = FULL_HOUR_RATE;

    // Boat 6 hired for half an hour at 14:00
    boats[5].isHired = true;
    boats[5].returnTime = 1430;
    boats[5].totalHoursHired = 0.5;
    boats[5].dailyEarnings = HALF_HOUR_RATE;

    // Checking boat availability at different times
    cout << "Checking for next available boat at 14:30:\n";
    findNextAvailableBoat(boats, NUM_BOATS);

    cout << "Checking for next available boat at 15:00:\n";
    findNextAvailableBoat(boats, NUM_BOATS);

    // Boat 7 hired for 1 hour at 15:30
    boats[6].isHired = true;
    boats[6].returnTime = 1630;
    boats[6].totalHoursHired = 1;
    boats[6].dailyEarnings = FULL_HOUR_RATE;

    // At the end of the day
    cout << "\nGenerating end of day report:\n";
    endOfDayReport(boats, NUM_BOATS);

    return 0;
}
