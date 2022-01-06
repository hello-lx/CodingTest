#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /*
     * @param : A string
     * @param : A set of word
     * @return: the number of possible sentences.
     */
    int wordBreak3(string& s, unordered_set<string>& dict) {
        //将字符全部转化为小写，并将dict转换成hash_stet存储，降低判断子串存在性的时间复杂度
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        unordered_set<string> hs;
        for(string x : dict) {
            transform(x.begin(), x.end(), x.begin(), ::tolower);
            hs.insert(x);
        }
        //dp[i]表示s[0:i](不含s[i])的拆分方法数
        int len = s.size();
        vector<int> dp(len + 1);

        //dp[0]表示空串的拆分方法数
        dp[0] = 1;       

        for (int i =0; i < len; i++){
            for (int j = i; j < len; j++){
                //若存在匹配，则进行状态转移
                if (hs.count(s.substr(i, j - i + 1))){
                    dp[j + 1] += dp[i];
                }
            }
        }
        return dp[len];
    }
};