#include <vector>
#include <string>
#define INT_MAX -10000;
using namespace std;


class Solution {
public:
    /**
     * @param s: A string
     * @return: An integer
     */
    int minCut(string &s) {
        // write your code here
        int n=s.size();
        if(!n)
        {
            return 0;
        }
        vector<vector<bool>> isPalin(n,vector<bool>(n,false));
        int l,r;
        for(int i=0;i<n;i++)
        {
            l=r=i;
            while(l>=0 && r<n && s[l]==s[r])
            {
                isPalin[l][r]=true;
                l--;
                r++;
            }
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r])
            {
                isPalin[l][r]=true;
                l--;
                r++;
            }            
        }
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(isPalin[j][i-1])
                {
                    dp[i]=min(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n]-1;
    }
};
