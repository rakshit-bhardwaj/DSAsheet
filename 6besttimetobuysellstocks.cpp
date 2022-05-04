#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int i, j, n = prices.size(), minp = INT_MAX, maxprofit = 0;
        for (i = 0; i < n; i++)
        {
            minp = min(minp, prices[i]);
            maxprofit = max(maxprofit, prices[i] - minp);
        }

        return maxprofit;
    }
};