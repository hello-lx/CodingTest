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
    乘法模运算的分配律：(a * b) % p = (a % p * b % p) % p；

    求 (a^n)%b，则 n == 2*k 或 n == 2k+1，
    1、当 n 为偶数时，(a^2k)%b = ((a^k)%b * (a^k)%b)%b
    2、当 n 为奇数时，(a^2k+1)%b = (a%b *(a^2k)%b)%b
    这里奇数时借用了偶数的结果，所以取模的位置不要漏了。
*/

class Solution {
public:
    int fastPower(int a, int b, int n) {
        if(n == 0)  return 1%b;
        long long product = fastPower(a, b, n>>1)%b;
        product *= product;
        return n%2 ? ((long long)(a%b)*(product%b))%b : product%b;
    }
};

