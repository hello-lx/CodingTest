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
    1、把除法換成減法操作，並用 XOR 運算先計算出符號(同號數 XOR 是 False，sign 為 1)，
        再把被除數和除數都取絕對值並拓展為 long 避免 overflow
    2、把商不斷左移一位 (*2) 到小於等於被除數的最大值、商也跟著一起左移
    3、res += 商, 被除數減掉第二步算出來的小於等於被除數的最大值
    4、回到步驟二，直到被除數小於除數
    5、返回商
*/

class Solution {
public:
    /**
     * @param dividend: the dividend
     * @param divisor: the divisor
     * @return: the result
     */
    int divide(int dividend, int divisor) {
        // write your code here
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
        }
        long divd = abs((long)dividend);
        long divs = abs((long)divisor);
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long res = 0;
        
        // 被除數大於等於除數就要進去計算，因為商 (p) 至少為 1
        while (divd >= divs) {
            long tmp = divs , p = 1;
            while (divd >= tmp << 1) 
            {
                tmp <<= 1;
                p <<= 1;
            }
            res += p;
            divd -= tmp;
        }
        return sign > 0 ? res : -res;
    }   
};
