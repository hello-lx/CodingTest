#include <vector>
#include <iostream>
#include <unordered_set>
#include <map>
using namespace std;

// 记忆化搜索:
// 利用memo[s]记录字符串s的切分方案，每次不断递归，枚举i为s的切割点进行搜索，
// 一旦memo[s]存在，返回即可，记忆化搜索剪枝。

class Solution {
public:
    /*
     * @param s: A string
     * @param wordDict: A set of words.
     * @return: All possible sentences.
     */
    vector<string> res ;
    vector<int> f [5000];
    int n;
    void dfs(int p, string s, string now) 
    {
        if (p == n) 
        {
            res.push_back(now);
            return;
        }
        
        if (p > 0) 
        {
            now += " ";
        }
        
        for (int i = 0 ; i < f[p].size(); i++) 
        {
            dfs(f[p][i], s, now + s.substr(p, f[p][i] - p));
        }
    }
    
    vector<string> wordBreak(string &s, unordered_set<string> &wordDict) 
    {
        // write your code here
        n = s.length();
        int i, j;
        
        for (i = n - 1; i >= 0; --i) {
            for (j = i + 1; j <= n; ++j) {
                if (wordDict.find(s.substr(i, j - i)) != wordDict.end())
                {
                    if (j == n || f[j].size() > 0) 
                    {
                        f[i].push_back(j);
                        cout << i << ' ' << j << endl;
                    }
                }
            }
        }
        
        dfs(0, s, "");
        return res;
    }
};

int main()
{
    string s = "lintcode";
    unordered_set<string> data = {"de","ding","co","code","lint"};
    Solution solution;
    solution.wordBreak(s, data);

    return 0;
}