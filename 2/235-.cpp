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
1、枚举质因子 i 从最小的质数2开始到取整sqrt(num)，依次判断 i 是否为 num 的因数，
   如果是那么存下 i 并且 num/=i ，继续判断。
2、如果剩下的 num 大于 1，说明剩下的数是大于 sqrt(num)的质因子，也要加入答案。
3、如何确定存下的因数一定是质数呢？因为一个非质数一定可以分解成几个质数的乘积，所以
   在判断到不是质数的因数之前这个因数就已经被分解了。
*/

class Solution {
public:
    /**
     * @param num: An integer
     * @return: an integer array
     */
    vector<int> primeFactorization(int num) {
        vector <int> factors;
        for (int i = 2; i * i <= num; i++){
            while (num % i == 0){
                factors.push_back(i);
                num /= i;
            }
        }
        if (num > 1){
            factors.push_back(num);
        }
        return factors;
    }
};
