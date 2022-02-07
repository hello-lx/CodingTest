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
算法：贪心
    回文串是一个正读和反读都一样的字符串，因此可以发现一个特点是所有字符最多只允许一种字符出现奇数次,
    其余均为偶数次。那么我们可以这样构造一个回文串，将出现奇数次的字符（如果有的话）置于中心位置，
    然后将剩余的偶数次字符不断放置在两侧。

算法思路
    题目需要我们构造出最长的回文串，因此我们可以想到用贪心的算法来解决这个问题
步骤
    统计每种字符出现的次数，注意本题需要大小写区分；

对于一个字符c，如果出现了cnt次，那么我们可以将这个字符在字符串两侧各放置 cnt/2个，
即一共使用了 cnt/2*2个（/为整除法），将它计入答案ans；

如果有字符出现奇数次，那么我们将其放在回文串中心，ans=ans+1

复杂度分析
空间复杂度：O(N)，N为字符串长度。

时间复杂度：O(N)，需要遍历到字符串中每个字符并进行一次计数。
*/

class Solution {
public:
    /**
     * @param s: a string which consists of lowercase or uppercase letters
     * @return: the length of the longest palindromes that can be built
     */
    int longestPalindrome(string &s) {
        // write your code here
        //cnt为计数数组
		//OddCount为是否有奇数次字符，1表示有，0表示无
		//ans为最终答案 
        int cnt[52];
        int OddCount = 0;
        int ans = 0;

        // 清空cnt数组 
        memset(cnt, 0, sizeof(cnt));

        // 统计字符串s中每种字母出现次数 
        for (char c: s) {
            if (c >= 97) {
                cnt[26 + c - 'a']++;
            }
            else {
                cnt[c - 'A']++;
            }
        }

        // 每种字符可使用cnt/2*2次
		// 若有字符出现奇数次，将OddCount值改为1 
        for (int i = 0; i < 52; i++) {
            ans+=cnt[i] / 2 * 2;
            if (cnt[i] % 2) {
            	OddCount = 1;
        	}
    	}

        //若有字符出现奇数次，答案加1 
    	ans+= OddCount;
        return ans;
    }
};
