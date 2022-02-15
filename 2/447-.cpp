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
     * @param reader: An instance of ArrayReader.
     * @param target: An integer
     * @return: An integer which is the first index of target.
     */
    int searchBigSortedArray(ArrayReader * reader, int target) {
        // write your code here
        int index = 1;
        while(reader->get(index) < target) index *= 2;

        int low = index/2, high = index;

        while (low + 1 < high) {
            int mid = low + (high-low)/2;

            if(reader->get(mid) < target) {
                low = mid;
            } else {
                high = mid;
            }
        }

        if(reader->get(low) == target) return low;
        else if(reader->get(high) == target) return high;
        return -1;        
    }
};
