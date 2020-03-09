#include <iostream>
#include <>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: An Integer
     */
    int climbStairs2(int n) {
        // write your code here
        std::vector<long long> result;
        result.push_back(1);
        result.push_back(1);
        result.push_back(2);
        if(n>=3)
        {
            for ( int i=3; i <= n; i++) {
                /* code */
            result.push_back(result[i-1]+result[i-2]+result[i-3]);
            }
            return result[n];
        }
        return result[n];
    }
};
