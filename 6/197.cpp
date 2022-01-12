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

// 计算每次排序需要的次数
// https://blog.csdn.net/qq_34672688/article/details/79557380


class Solution {
public:
    /**
     * @param A: An array of integers
     * @return: A long integer
     */
    long long permutationIndex(vector<int> &A) {
        // write your code here
        if (A.size() < 2) {
            return 1;
        }
        int i = A.size() - 2;
        long long res = 0, fac = 1;
        while (i >= 0) {
            int left = i + 1;
            int temp = 0;
            while (left < A.size()) {
                if (A[i] > A[left]) {
                    temp++;
                }
                left++;
            }
            res += temp * fac;
            fac *= A.size() - i;
            i--;
        }
        return res + 1;
    }
};      