class HotelPointsCalculator
{
public:
    /// @brief Default constructor
    HotelPointsCalculator();

    /// @brief Gets user input about hotel prices and points
    void GetUserInput();

    /// @brief If the user has a chase card, use these values to make a purchase decision
    void GetChaseInput();

    /// @brief Calculates the hotel price in points
    void CalculateHotelPoints();

    /// @brief Clearly displays all totals to the user
    void DisplayValues();

    /// @brief Tell user which option to purchase hotel with based on the lowest price
    void MakeBuyerHotelDecision();

private:
    float m_hotelCashPriceFromChaseTravel = 0.0f; ///< Hotel total price in cash from chase travel portal
    float m_hotelPointsFees = 0.0f;               ///< Hotel fees when paying in points

    float m_hotelPriceInCash = 0.0f; ///< Hotel price in cash from the hotel website or other source
    int m_hotelPriceInPoints = 0;    ///< The hotel price in points from the hotel's webiste

    float m_hotelPointsToCashValue = 0.0f; ///< The conversion of hotel points to cash value
    float m_chasePointsInUSD = 0.0f;       ///< The chase points 1:1 converted to USD
};