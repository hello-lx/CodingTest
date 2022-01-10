#include <string>
#include <vector>
using namespace std;


class Solution {
public:
    /**
     * @param n: n pairs
     * @return: All combinations of well-formed parentheses
     */
    void dfs(std::string s, int d, int N, vector<string>& res, int left, int right)
    {
        if (d == N * 2 - 1)
        {
            res.push_back(s + ')');
            return;
        }
        if (left < N)
            dfs(s + "(", d + 1, N, res, left + 1, right);
        if (right < N && right < left)
            dfs(s + ")", d + 1, N, res, left, right + 1);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("(", 1, n, res, 1, 0);
        return res;
    }
};
