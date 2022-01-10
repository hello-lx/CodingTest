#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Solution {
public:
    void dfs(string s, vector<string>& current, vector<string>& res)
    {
        if (s.empty())
        {
            if (current.size() != 4)
            {
                return;
            }
            res.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
            return;
        }

        if (current.size() >= 4)
            return;

        for (int i = 1; s.length() >= i && i <= 3; i++)
        {
            string tmp = s.substr(0, i);
            if (i >= 2)
            {
                if (tmp == "00" || tmp == "000")
                    continue;
                if (tmp[0] == '0')
                    continue;
            }
            if (i == 3)
            {
                int num = atoi(tmp.c_str());
                if (num > 255)
                    break;
            }
            current.push_back(tmp);
            dfs(s.substr(i), current, res);
            current.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string &s) {
        vector<string> current;
        vector<string> res;
        dfs(s, current, res);
        return res;
    }
};


int main()
{
    string data = "25525511135";
    Solution s;
    s.restoreIpAddresses(data);
}