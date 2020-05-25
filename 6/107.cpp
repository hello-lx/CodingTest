#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;


class Solution {
public:
    /*
     * @param s: A string
     * @param dict: A dictionary of words dict
     * @return: A boolean
     */
    bool wordBreak(string &s, unordered_set<string> &dict) {
        // write your code here
        int len=s.size();
        if(s=="") return true;
        vector<bool> dp(len+1,false);
        dp[0]=true;
        for(int i=1;i<=len;i++){
            for(int j=0;j<i;j++){
                if(dp[j]&&dict.count(s.substr(j,i-j))>=1)
                {
                    dp[i]=true;
                    break;
                }
            }
            cout<<i<<" "<<dp[i]<<endl;
        }
        return dp[len];
    }
};
