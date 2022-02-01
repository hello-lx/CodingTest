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
     * @param numbers: An array of Integer
     * @param target: target = numbers[index1] + numbers[index2]
     * @return: [index1, index2] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &numbers, int target) {  
        // O(n)
        map <string, int> map;
        vector<int> answer;

        // write your code here
        for (int i = 0; i < numbers.size(); i++) {
            string key = to_string(target - numbers[i]);

            if (map[key]) {
                answer.push_back(map[key] - 1);
                answer.push_back(i);
                return answer;
            }

            map[to_string(numbers[i])] = i + 1;
        }

/*
        // write your code here  O(n^2)
        if(numbers.size() < 2) return {};
        int n = numbers.size();
        for(int i=0; i<numbers.size()-1; i++)
            for(int j=i+1; j<numbers.size(); j++)
            {
                if(numbers[i] + numbers[j] == target)
                    return {i, j};
            }
        
        return {};
*/

    }
};
