/*
 * Complete the function below.
 */
vector < unsigned int > stockMaximize(TestEntries testEntries)
{
    vector<unsigned int> result;
    for (auto & testEntry : testEntries)
    {
        int n = (testEntry.end() - testEntry.begin());
        long max_current_future_price = 0;
        long profit = 0;
        for (int i=n-1; i>=0; --i) {
            max_current_future_price = (max_current_future_price >= testEntry[i]) ? max_current_future_price : testEntry[i];
            profit += (long)max_current_future_price - testEntry[i];
        }
        result.push_back(profit);
    }
    return result;
}