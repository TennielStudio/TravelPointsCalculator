/// @brief Calculates the points to prize value and informs the user on which method they should pay with for the most savings
// Goals:
// 1. Have the user enter takeoff/landing destination, dates, and number of travlers
// 2. Pull in data from the internet to inform which flights they'll get best value for their money
class AwardPointsCalculator
{
public:
    /// @brief Default constructor
    AwardPointsCalculator();

    /// @brief Calculates the cents per point values and does the points to cash conversions
    void CalculateFlightValue();

    /// @brief Calculates the chase points value in USD
    void CalculateChasePoints();

    /// @brief Gets the user's input for their flight's points and cash prices
    void GetUserInput();

    /// @brief Clearly displays the different cash and point conversion avlues
    void DisplayValues();

    /// @brief Using compared points and cash value options, make a decision on which option to purchase with
    void MakeBuyerDecision();

private:
    float m_departingCashPrice = 0.0f; ///< The departing flight's cash price
    float m_returningCashPrice = 0.0f; ///< The returning flight's cash price
    float m_cashPriceFees = 0.0f;      ///< Any cash price fees

    int m_departingPoints = 0; ///< The departing flight's point value
    int m_returningPoints = 0; ///< The returning flight's point value
    int m_pointFees = 0;       ///< Fees included with using points

    float m_chaseInCash = 0.0f;    ///< Flight cash value on chase's webiste
    int m_chasePointsInUSD = 0.0f; ///< The cash value in points on chase's website + fees
    float m_chaseFees = 0.0f;      ///< Fees included with using chase points

    int m_totalPointsConvertedToUSD = 0; ///< Total flight points converted into USD amount
    int m_totalInCash = 0;               ///< Total flight cash price
};