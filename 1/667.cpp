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

算法：DP

设dp[i][j]表示在s[i...j]中最长回文序列的长度。

对于初始化区间长度

1、长度为0时，dp[i][i] = 1

2、对于 dp[i][j]，假设s[i] != s[j]
   那么在sub(i,j)的最大回文串中,s[i]与s[j]不会同时出现，那么sub(i,j)的最大回文串要么出现在sub(i+1,j),要么出现在sub(i,j-1)，
   因此我们的状态转移方程就得到了dp[i][j] = max(dp[i+1][j], dp[i][j-1])

3、假设s[i]==s[j]
   那么直接认为这俩个匹配，会同时出现在结果中，然后加上sub(i+1,j-1)的最大回文串，即dp[i][j] = dp[i+1][j-1] + 2

4、最后的结果就在dp[0][len_s-1]
  

复杂度分析

时间复杂度O(len(s)*len(s))
    嵌套循环，顺着i减小的方向，以j增大的方向遍历
空间复杂度O(len(s)*len(s))
    二维dp的大小
*/

class Solution {
public:
    /**
     * @param s: the maximum length of s is 1000
     * @return: the longest palindromic subsequence's length
     */
    int longestPalindromeSubseq(string &s) {
        // write your code here
        int size = s.size();
        if (size <= 1){
            return size;
        }
        int dp[size][size];
        //初始化        
        memset(dp,0,sizeof dp);
        for (int i = 0; i < size; ++i) {
            dp[i][i] = 1;
        }
        for (int i = size - 1; i >= 0; --i) {
            for (int j = i + 1; j < size; ++j) {
                if (s[i] == s[j]) {//s[i]==s[j]时的转移方程
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } 
                else {//s[i]！=s[j]时的转移方程
                    dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
                }
            }
        }
        //最后结果在dp[0][size - 1]中
        return dp[0][size - 1];
    }
};
