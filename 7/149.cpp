#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        if(prices.size() == 0) return 0;
        
        int minPro = prices[0];
        int maxPro = 0;
        for (int i=0; i<prices.size(); i++)
        {
            minPro = min(minPro, prices[i]);
            maxPro = max(maxPro, prices[i] - minPro);
        }
        return maxPro;
    }
};
