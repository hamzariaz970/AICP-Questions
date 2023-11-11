#include <iostream>
using namespace std;

class ElectricMountainRailway{
    private:
        // constant data shared among all trains
        const int totalTrains = 8;
        const int coachesPerTrain = 6;
        const int seatsPerCoach = 80;
        const int totalSeats = coachesPerTrain * seatsPerCoach;
        const double ticketPrice = 25.0;
        const string departureToMountain[4] = {"09:00", "11:00", "13:00", "15:00"};
        const string returnFromMountain[4] = {"10:00", "12:00", "14:00", "16:00"};

        int passengerCount[8]; //array to hold passenger count for each train
        double revenue[8]; // array to hold revenue for each train
        int seatsAvailable[8]; // array to hold no. of seats available for each train

    public:
        ElectricMountainRailway()
        {
            for (int i = 0; i < totalTrains; i++)
            {
                passengerCount[i] = 0;
                revenue[i] = 0.0;
                seatsAvailable[i] = totalSeats;
            }
            // initializing last train to have 2 more extra coaches
            seatsAvailable[totalTrains - 1] = totalSeats + (2 * seatsPerCoach);
        }


        void displayTrainStatus()
        {   
            cout << "**********************************************************" << endl;
            cout << "\t\t_________________________________\t\t\n\t\tTrain Times and Available Tickets\t\t\n\t\t_________________________________\t\t" << endl;
    
            for (int i = 0; i < 4; i++) 
            {
                cout << "Train to the mountain at " << departureToMountain[i];;
                if (seatsAvailable[i] == 0) cout << " - Closed" << endl;
                else cout << " - Available Tickets: " << seatsAvailable[i];
                cout << endl;
            }
            cout << endl;
            for (int i = 0; i < 4; i++) 
            {
                cout << "Train from the mountain at " << returnFromMountain[i];
                if (seatsAvailable[i+4] == 0) cout << " - Closed" << endl;
                else cout << " - Available Tickets: " << seatsAvailable[i + 4];
                cout << endl;
            }
              cout << "**********************************************************" << endl;
        }


        void purchaseTickets(int trainIndex, int numberOfPassengers)
        {   
            // if the arguments passed are invalid
            if (trainIndex < 0 || trainIndex >= totalTrains || numberOfPassengers <= 0 || numberOfPassengers > seatsAvailable[trainIndex]) {
                cout << "Purchase Error: Invalid input" << endl;
                return;
            }
            // calculating how many passengers can travel for free (every 10th passenger)
            int discountTickets = numberOfPassengers / 10;
            int chargedPassengers = numberOfPassengers - discountTickets;
            // calculating final price to be charged
            double totalCost = chargedPassengers * ticketPrice;

            // adding passengers to the specific train booked
            passengerCount[trainIndex] += numberOfPassengers;
            // adding to revenue
            revenue[trainIndex] += totalCost;
            // reducing available seats
            seatsAvailable[trainIndex] -= numberOfPassengers;
        }


    void endOfDaySummary() 
    {
        int totalPassengers = 0;
        double totalRevenue = 0.0;
        int maxPassengers = 0;
        string maxPassengerTrainTime;

        cout << "**********************************************************" << endl;
        cout << "\tEnd of Day Summary" << endl;
        cout << "**********************************************************" << endl;

        for (int i = 0; i < totalTrains; i++) {
            totalPassengers += passengerCount[i];
            totalRevenue += revenue[i];

            // Keeping track of train with highest numbe of passengers
            if (passengerCount[i] > maxPassengers) {
                maxPassengers = passengerCount[i];
                if (i < 4) {
                    maxPassengerTrainTime = departureToMountain[i];
                } else {
                    maxPassengerTrainTime = returnFromMountain[i - 4];
                }
            }
            // trains to mountain
            if (i < 4) cout << "Train to the mountain at " << departureToMountain[i];
    
            // trains from mountain
            else cout << "Train from the mountain at " << returnFromMountain[i - 4];
            // printing passengers and revenue earned
            cout << " - Passengers: " << passengerCount[i] << ", Revenue: $" << revenue[i] << endl;
        }

        cout << "**********************************************************" << endl;

        // Total summary
        cout << "Total Passengers: " << totalPassengers << ", Total Revenue: $" << totalRevenue << endl;
        cout << "Most Passengers on Train: " << maxPassengerTrainTime << " - " << maxPassengers << " Passengers" << endl;

        cout << "**********************************************************" << endl;
    }

};