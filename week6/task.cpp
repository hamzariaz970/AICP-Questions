#include <iostream>
#include <string>
#include <stack>
using namespace std;

const double CEMENT_PRICE = 3.0;
const double GRAVEL_PRICE = 2.0;
const double SAND_PRICE = 2.0;

struct Sack {
    char type;
    double weight;

    Sack(char t, double w) : type(t), weight(w) {}
};


bool isValidSack(const Sack& sack);
double calculateRegularPrice(int cement, int gravel, int sand);
double calculateDiscountedPrice(int cement, int gravel, int sand);

// Task 1 - Checking valid entries
bool isValidSack(const Sack& sack) {
    switch (sack.type) {
        case 'C':
            return sack.weight > 24.9 && sack.weight < 25.1;
        case 'G':
            return sack.weight > 49.9 && sack.weight < 50.1;  // Fixed validation for gravel
        case 'S':
            return sack.weight > 49.9 && sack.weight < 50.1;
        default:
            return false;
    }
}

// Task 2 - Inputting sacks
stack<Sack> inputSacks() {
    stack<Sack> sacks;
    char type;
    double weight;

    while (true) {
        cout << "Enter sack type (C, G, S) or 'X' to finish: ";
        cin >> type;

        if (type == 'X' || type == 'x') {
            break;
        }

        cout << "Enter sack weight: ";
        cin >> weight;

        sacks.push(Sack(type, weight));
    }

    return sacks;
}

// Task 3 - Determining final price
void determineFinalPrice(stack<Sack> sacks) {
    int totalCement = 0, totalGravel = 0, totalSand = 0;
    int rejected = 0;

    while (!sacks.empty()) {
        Sack currentSack = sacks.top();
        sacks.pop();

        if (isValidSack(currentSack)) {
            switch (currentSack.type) {
                case 'C':
                    totalCement++;
                    break;
                case 'G':
                    totalGravel++;
                    break;
                case 'S':
                    totalSand++;
                    break;
            }
        } else {
            rejected++;
        }
    }

    double regularPrice = calculateRegularPrice(totalCement, totalGravel, totalSand);
    double discountedPrice = calculateDiscountedPrice(totalCement, totalGravel, totalSand);

    cout << "Total cement sacks: " << totalCement << "\n";
    cout << "Total gravel sacks: " << totalGravel << "\n";
    cout << "Total sand sacks: " << totalSand << "\n";
    cout << "Total rejected sacks: " << rejected << "\n";
    cout << "Regular price: $" << regularPrice << "\n";
    cout << "Discounted price: $" << discountedPrice << "\n";
    cout << "Amount saved: $" << (discountedPrice < regularPrice ? regularPrice - discountedPrice : 0) << "\n";
}

double calculateRegularPrice(int cement, int gravel, int sand) {
    return cement * CEMENT_PRICE + gravel * GRAVEL_PRICE + sand * SAND_PRICE;
}

double calculateDiscountedPrice(int cement, int gravel, int sand) {
    const double discountPackPrice = 10.0;
    int specialPacks = min({cement, gravel / 2, sand / 2});
    double regularPrice = calculateRegularPrice(cement, gravel, sand);
    double discountAmount = specialPacks * (11 - discountPackPrice);  

    return regularPrice - discountAmount;
}


int main() {
    stack<Sack> sacks = inputSacks();
    determineFinalPrice(sacks);

    return 0;
}

