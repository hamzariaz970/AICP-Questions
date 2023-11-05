#include <iostream>
#include <iomanip>

using namespace std;

class ComputerShop {
    private:
        // initializing the shop with these constants so that every object a=has atleast these
        const static int MAX_ITEMS = 16;
        double basePrice;    

        // structure to hold item data
        struct Item {
            string category;
            string itemCode;
            string description;
            double price;
        };

        // All available items in an array
        Item allItems[MAX_ITEMS] = {
            {"Case", "A1", "Compact", 75.00},
            {"Case", "A2", "Tower", 150.00},
            {"RAM", "B1", "8 GB", 79.99},
            {"RAM", "B2", "16 GB", 149.99},
            {"Main HDD", "C1", "1 TB HDD", 49.99},
            {"Main HDD", "C2", "2 TB HDD", 89.99},
            {"Main HDD", "C3", "4 TB HDD", 129.99},
            {"SSD", "D1", "240 GB SSD", 59.99},
            {"SSD", "D2", "480 GB SSD", 119.99},
            {"Second HDD", "E1", "1 TB HDD", 49.99},
            {"Second HDD", "E2", "2 TB HDD", 89.99},
            {"Second HDD", "E3", "4 TB HDD", 129.99},
            {"Optical Drive", "F1", "DVD/Blu-Ray Player", 50.00},
            {"Optical Drive", "F2", "DVD/Blu-Ray Re-writer", 100.00},
            {"Operating System", "G1", "Standard Version", 100.00},
            {"Operating System", "G2", "Professional Version", 175.00}
        };

        // Array to hold chosen items by user
        Item chosenItems[MAX_ITEMS];
        // counter to hold the number of items chosen (to calculate discount)
        int itemCount;

    public:
        ComputerShop() {
            basePrice = 200;
            itemCount = 0;
            }

        // Function to start placing an order
        void orderItems(string categories[], int size) {
            for (int i = 0; i < size; i++) {
                // Display items from the specific category passed in function arguement
                displayItemsByCategory(categories[i]);
                // ask user for innput
                string code = promptForItemCode();
                // add chosen item into chosenItem array
                updateChosenItems(code, categories[i]);
            }
        }

        // Function to display all the items of one specific category passed in argument
        void displayItemsByCategory(const string& category) {
            cout << "Displaying " << category << " components: " << endl;
            cout << "********************************************************************" << endl;
            cout << left << setw(20) << "Category" << setw(15) << "Item Code" << setw(25) << "Description" << setw(10) << "Price($)" << endl;

            // print all those items with matching categories
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (allItems[i].category == category) {
                    cout << left << setw(20) << allItems[i].category << setw(15) << allItems[i].itemCode << setw(25) << allItems[i].description << setw(10) << allItems[i].price << endl;
                }
            }
            cout << "********************************************************************" << endl;
        }

        // function to ask user for item code for a specific category and validate it
        string promptForItemCode() {
            string code;
            bool isValid = false;

            while (!isValid) {
                cout << "Enter item code for component: ";
                cin >> code;

                for (int i = 0; i < MAX_ITEMS; i++) {
                    if (allItems[i].itemCode == code) {
                        isValid = true;
                        break;
                    }
                }

                if (!isValid) {
                    // incorrect code entered
                    cout << "Invalid item code. Please try again." << endl;
                }
            }
            return code;
        }

        // function to return item according to code passed in argument
        Item getItem(string code) {
            for (int i = 0; i < MAX_ITEMS; i++) {
                if (allItems[i].itemCode == code) {
                    return allItems[i];
                }
            }
            Item emptyItem = {"", "", "", 0};
            return emptyItem;
        }

        // if 2 same type of parts are chosen, update the previous part to new selection
        void updateChosenItems(string code, const string& category) {
            Item item = getItem(code);

            for (int i = 0; i < itemCount; i++) {
                if (chosenItems[i].category == category) {
                    cout << "Replacing existing " << category << " selection..." << endl;
                    for (int j = i; j < itemCount - 1; j++) {
                        chosenItems[j] = chosenItems[j + 1];
                    }
                    itemCount--;
                }
            }

            chosenItems[itemCount++] = item;
            cout << "Added " << item.description << " to your order." << endl;
        }

        // Function to calculate price of all parts
        double calculateTotal() {
            double total = basePrice;
            for (int i = 0; i < itemCount; i++) {
                total += chosenItems[i].price;
            }
            return total;
        }

        // Discount applied based on additional parts chosen
        double applyDiscount() {
            double discount = 0;
            double total = calculateTotal();

            // One additional item chosen
            if (itemCount - 3 == 1) {
                discount = 0.05 * total;
            } else if (itemCount - 3 >= 2) { // Two or more additional items chosen
                discount = 0.10 * total;
            }
            return discount;
        }

        // Function to display final order that is to be placed
        void displayOrderSummary() {
            double total = calculateTotal();
            double discount = applyDiscount();

            cout << "\nOrder Summary:" << endl;
            cout << "************************************************" << endl;

            for (int i = 0; i < itemCount; i++) {
                cout << left << setw(20) << chosenItems[i].category << setw(15) << chosenItems[i].itemCode << setw(25) << chosenItems[i].description << setw(10) << chosenItems[i].price << endl;
            }

            cout << "\nTotal Price (without discount): $" << total << endl;
            cout << "Discount applied: $" << discount << endl;
            cout << "Final Price: $" << total - discount << endl;
            cout << "************************************************" << endl;
        }
        
        ~ComputerShop() {}
};

