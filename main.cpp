#include <iostream>
#include "AwardPointsCalc.hpp"
#include "HotelPointsCalc.hpp"

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
    else if (isFlight == "no")
    {
        HotelPointsCalculator hotelCalculator; // create the object for the hotel calculator
        hotelCalculator.CalculateHotelPoints();
    }
    return 0;
}