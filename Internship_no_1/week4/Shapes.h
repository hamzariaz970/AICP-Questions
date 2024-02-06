#include <iostream>
using namespace std;
#include <cmath>

const int CNIC_LAST_DIGIT = 9;

class Hexagon{
    private:
        int sideLength;

    public: 
        Hexagon()
        {
            sideLength = CNIC_LAST_DIGIT; 
        }    

        double calcArea()
        {
            return 1.5*1.732*sideLength;
        }

        int calcPeri()
        {
            return 6 * sideLength;
        }

        int calcAngleSum()
        {
            int interiorAngle = 120;
            return 6 * interiorAngle;
        }

        void display()
        {
            cout << "Area: " << calcArea() << endl;
            cout << "Perimeter: " << calcPeri() << endl;
            cout << "Sum of angles: " << calcAngleSum() << endl;
        }


        ~Hexagon(){}

};


#include <iostream>
using namespace std;

class Square{
    private:
        int sideLength;

    public: 
        Square()
        {
            sideLength = CNIC_LAST_DIGIT + 1; 
        }    

        double calcAreaSquare()
        {
            return pow(sideLength, 2);
        }

        int calcPeriSquare()
        {
            return 4 * sideLength;
        }


        void display()
        {
            cout << "Area: " << calcAreaSquare() << endl;
            cout << "Perimeter: " << calcPeriSquare() << endl;

        }


        ~Square(){}

};
