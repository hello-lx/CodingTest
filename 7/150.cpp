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
        // write your code here
        if(prices.size() == 0) return 0;
        
        int res = 0;
        for(int i=1; i<prices.size(); i++){
            res += max(0, prices[i]-prices[i-1]);
        }
        return res;
    }
};
