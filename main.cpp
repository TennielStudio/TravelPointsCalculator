#include <iostream>
#include "AwardPointsCalc.hpp"

using namespace std;

int main()
{
    string isFlight = "";
    float enteredCashPrice;

    cout << "Is this a flight? " << endl;
    cin >> isFlight;

    if (isFlight == "yes")
    {
        AwardPointsCalculator flightCalculator; // create the object for the flight calculator
        flightCalculator.CalculateFlightValue();
    }

    return 0;
}