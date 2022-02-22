#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;

#define INT_MIN -99999999999
#define INT_MAX 99999999999

class Solution {
public:
    /**
     * @param numbers: Give an array numbers of n integer
     * @return: Find all unique triplets in the array which gives the sum of zero.
     */
    vector<vector<int>> threeSum(vector<int> &numbers) {
        // write your code here
        std::sort(numbers.begin(), numbers.end());
        std::set<std::vector<int>> triples;
        for (int first = 0; first < numbers.size(); ++first) {
            for (int second = first+1, third = numbers.size()-1; second < third;) 
            {
                int sum = numbers[first] + numbers[second] + numbers[third];
                if (sum < 0) 
                {
                    ++second;
                } 
                else if (sum > 0) 
                {
                    --third;
                } 
                else 
                {
                    triples.insert({numbers[first], numbers[second], numbers[third]});
                    ++second, --third;
                }
            }
        }
        return std::vector<std::vector<int>>{triples.begin(), triples.end()};
    }
};
