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
     * @param target: An integer
     * @return: return the sum of the three integers, the sum closest target.
     */
    int threeSumClosest(vector<int> &numbers, int target) 
    {
        // write your code here
        int n = numbers.size(), mindiff = INT_MAX, diff;
		sort(numbers.begin(), numbers.end());
		for (int left = 0; left < n - 2; ++left)
			if (left < 1 || numbers[left] > numbers[left - 1]) 
            {
				int mid = left+1, right = n-1, target2 = target-numbers[left];
				while (mid < right) 
                {
					diff = numbers[mid] + numbers[right] - target2;
					if (!diff)
						return target;
					else if (diff > 0)
						--right;
					else
						++mid;
					if (abs(mindiff) > abs(diff))
						mindiff = diff;
				}
			}
		return mindiff + target;
    }
};
