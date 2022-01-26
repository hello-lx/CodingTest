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
     * @param array: an integer array
     * @return: nothing
     */
    void pancakeSort(vector<int> &array) {
        // Write your code here
        int n = array.size();
        for(int i = n - 1; i > 0; i--) {
            // 执行n-1次，因为最后剩一个最小的在第一个，不用处理。
            int Max = 0;
            for(int j = 1; j <= i; j++ ) {
                if(array[j] > array[Max]){
                    Max = j;
                }
            }
            if(Max != 0 && Max != i) {
                FlipTool::flip(array, Max);
                FlipTool::flip(array, i);
            } else if(Max == 0) {
                FlipTool::flip(array, i);
            }
        }
    }
};
