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

/*
算法：二分

此题有两种做法，一种是牛顿迭代法，一种是二分，这里介绍二分法
    二分浮点数与寻常二分不同的是while中变成了whlie(left+eps<right)
    注意小数情况，若x<1将右边界扩大到1可避免结果错误（比如0.04=0.2*0.2）如果我们不将x右边界扩大到1，
    则无法在[0,0.04]的区间范围内找到正解
  

复杂度分析
    时间复杂度O(log(x))
    二分的复杂度
    空间复杂度O(1)
    无需额外空间
*/

class Solution {
public:
    /**
     * @param x: a double
     * @return: the square root of x
     */
    double sqrt(double x) {
        // write your code here
        double left = 0,right = x,mid;
        if (right < 1) {
            right = 1;
        }
        while (left + 1e-12 < right) {
            mid = left + (right - left) / 2;
            if (mid * mid < x) {
                left = mid;
            }
            else{
                right = mid;
            }
        }
        return left;
    }
};
