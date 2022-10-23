#include "AwardPointsCalc.hpp"
#include <iostream>

using namespace std;

float g_preferredPoints = 1.25; // The chase preferred points cash:point value (1:1.25)

AwardPointsCalculator::AwardPointsCalculator()
{
}

void AwardPointsCalculator::CalculateChasePoints()
{
    cout << "Please enter the price on Chase's webiste: " << endl;
    cin >> m_chaseInCash;
    cout << "Please enter any Chase fees if using points: " << endl;
    cin >> m_chaseFees;
    m_chasePointsInUSD = (m_chaseInCash / g_preferredPoints) + m_chaseFees;
}

void AwardPointsCalculator::GetUserInput()
{
    cout << "Please enter departing points and departing cash price: ";
    cin >> m_departingPoints >> m_departingCashPrice;

    cout << "Please enter returning points and returning cash price: ";
    cin >> m_returningPoints >> m_returningCashPrice;

    cout << "Please enter any cash price fees: ";
    cin >> m_cashPriceFees;

    cout << "Please enter any points fees: ";
    cin >> m_pointFees;
    cout << endl;
}

void AwardPointsCalculator::CalculateFlightValue()
{
    GetUserInput();

    CalculateChasePoints();

    cout << endl;
    cout << "--------CENTS PER POINT---------" << endl;
    float departingCentsPerPoint = ((m_departingCashPrice / m_departingPoints) * 100);
    float returninCentsPerPoint = ((m_returningCashPrice / m_returningPoints) * 100);
    cout << "Departing airline cent per point: " << departingCentsPerPoint << endl;
    cout << "Returning airline cent per point: " << returninCentsPerPoint << endl;

    int totalPoints = (m_returningPoints + m_departingPoints);
    m_totalPointsConvertedToUSD = ((m_returningPoints + m_departingPoints) / 100) + m_pointFees;
    m_totalInCash = m_departingCashPrice + m_returningCashPrice + m_cashPriceFees;

    DisplayValues();

    MakeBuyerDecision();
}

void AwardPointsCalculator::DisplayValues()
{
    cout << endl;
    cout << "--------CASH COMPARISONS---------" << endl;
    cout << "Airline cash value: $" << m_totalInCash << endl;
    cout << "Chase cash value: $" << m_chaseInCash << endl;

    cout << endl;
    cout << "--------POINTS TO CASH COMPARISONS---------" << endl;
    cout << "Airline points to cash value: $" << m_totalPointsConvertedToUSD << endl;
    cout << "Chase points converted to 1:1 value + fees: $" << m_chasePointsInUSD << endl;
}

void AwardPointsCalculator::MakeBuyerDecision()
{
    cout << endl;
    cout << "--------DECISION----------" << endl;
    if (m_totalInCash < m_chaseInCash && m_totalInCash < m_totalPointsConvertedToUSD && m_totalInCash < m_chasePointsInUSD)
    {
        cout << "BUY IN CASH ON AIRLINE WEBSITE." << endl;
    }
    else if (m_chaseInCash < m_totalInCash && m_chaseInCash < m_totalPointsConvertedToUSD && m_chaseInCash < m_chasePointsInUSD)
    {
        cout << "BUY IN CASH ON CHASE WEBSITE." << endl;
    }
    else if (m_totalPointsConvertedToUSD < m_totalInCash && m_totalPointsConvertedToUSD < m_chaseInCash && m_totalPointsConvertedToUSD < m_chasePointsInUSD)
    {
        cout << "BUY IN POINTS ON AIRLINES WEBSITE." << endl;
    }
    else if (m_chasePointsInUSD < m_totalInCash && m_chasePointsInUSD < m_totalPointsConvertedToUSD && m_chasePointsInUSD < m_chaseInCash)
    {
        cout << "BUY IN POINTS ON CHASE WEBISTE." << endl;
    }
}