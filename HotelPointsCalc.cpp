#include "HotelPointsCalc.hpp"
#include <iostream>

using namespace std;

float g_preferredChasePoints = 1.25; // The chase preferred points cash:point value (1:1.25)

HotelPointsCalculator::HotelPointsCalculator()
{
}

void HotelPointsCalculator::GetChaseInput()
{
    cout << "Please enter hotel total price from Chase travel portal: " << endl;
    cin >> m_hotelCashPriceFromChaseTravel;
    cout << "Please enter hotel fees if using Chase points: " << endl;
    cin >> m_hotelPointsFees;
    m_chasePointsInUSD = (m_hotelCashPriceFromChaseTravel / g_preferredChasePoints) + m_hotelPointsFees;
}

void HotelPointsCalculator::GetUserInput()
{
    cout << "Please enter hotel total price in cash (including fees): " << endl;
    cout << "Note: This total should come directly from the hotel website." << endl;
    cin >> m_hotelPriceInCash;

    cout << "Please enter the hotel total in points from the hotel's website: " << endl;
    cin >> m_hotelPriceInPoints;
}

void HotelPointsCalculator::CalculateHotelPoints()
{
    GetUserInput();

    GetChaseInput();

    cout << endl;
    cout << "--------CENTS PER POINT---------" << endl;
    float hotelCentsPerPoint = ((m_hotelPriceInCash / m_hotelPriceInPoints) * 100);
    cout << "Hotel website cent per point (if you transfer points in from Chase): " << hotelCentsPerPoint << endl;
    cout << "Chase cent per point: " << g_preferredChasePoints << endl;

    m_hotelPointsToCashValue = m_hotelPriceInPoints / 100;

    DisplayValues();
}

void HotelPointsCalculator::DisplayValues()
{
    cout << endl;
    cout << "--------CASH COMPARISONS---------" << endl;
    cout << "Hotel cash value: $" << m_hotelPriceInCash << endl;
    cout << "Chase cash value: $" << m_hotelCashPriceFromChaseTravel << endl;

    cout << endl;
    cout << "--------POINTS TO CASH COMPARISONS---------" << endl;
    cout << "Hotel points to cash value: $" << m_hotelPointsToCashValue << endl; // TODO: add fees later
    cout << "Chase points converted to 1:1 value + fees: $" << m_chasePointsInUSD << endl;
    cout << endl;

    MakeBuyerHotelDecision();
}

void HotelPointsCalculator::MakeBuyerHotelDecision()
{
    cout << "--------DECISION----------" << endl;
    if (m_hotelPriceInCash < m_hotelCashPriceFromChaseTravel && m_hotelPriceInCash < m_hotelPointsToCashValue && m_hotelPriceInCash < m_chasePointsInUSD)
    {
        cout << "BUY IN CASH ON HOTEL WEBSITE." << endl;
    }
    else if (m_hotelCashPriceFromChaseTravel < m_hotelPriceInCash && m_hotelCashPriceFromChaseTravel < m_hotelPointsToCashValue && m_hotelCashPriceFromChaseTravel < m_chasePointsInUSD)
    {
        cout << "BUY IN CASH ON CHASE WEBSITE." << endl;
    }
    else if (m_hotelPointsToCashValue < m_hotelPriceInCash && m_hotelPointsToCashValue < m_hotelCashPriceFromChaseTravel && m_hotelPointsToCashValue < m_chasePointsInUSD)
    {
        cout << "BUY IN POINTS ON HOTEL WEBSITE." << endl;
    }
    else if (m_chasePointsInUSD < m_hotelPriceInCash && m_chasePointsInUSD < m_hotelCashPriceFromChaseTravel && m_chasePointsInUSD < m_hotelPointsToCashValue)
    {
        cout << "BUY IN POINTS ON CHASE WEBSITE." << endl;
    }
}
