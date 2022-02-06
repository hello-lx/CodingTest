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
     * @param x: An integer
     * @return: The sqrt of x
     */
    int sqrt(int x) {
        // write your code here
        double l = 0, r = 1e10;
        while(r - l > 1e-3){
            double mid = (l + r) / 2;
            if(mid*mid > x) r = mid;
            else l = mid;
        }
        return int(r);
    }
};
