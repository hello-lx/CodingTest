#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    /**
     * @param digits: A digital string
     * @return: all posible letter combinations
     */
    vector<string> letterCombinations(string &digits) {
        // write your code here
        vector<string> result;
        if(digits.empty())
            return result;
        vector<string> keypad({"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});
        function<void(const char*,string)> dfs = [&dfs,&keypad,&result](const char*pd,string res)
        {
            if(!*pd)
                result.push_back(res);
            else
                for(auto c:keypad[*pd-'2'])
                    dfs(pd+1,res+c);
        };
        dfs(digits.c_str(),"");
        return result;

    }
};


/*
class Solution {
public:
    vector<string> letterCombinations(string &digits) {
        // write your code here
        map<char, vector<string>> data = {
            {'2', {"a", "b", "c"}}, {'3', {"d", "e", "f"}},
            {'4', {"g", "h", "i"}}, {'5', {"j", "k", "l"}},
            {'6', {"m", "n", "o"}}, {'7', {"p", "q", "r", "s"}},
            {'8', {"t", "u", "v"}}, {'9', {"w", "x", "y", "z"}},
        };
        
        vector<string> result = {};
        vector<vector<string>> mergeData;
        for(auto c: digits)
            mergeData.push_back(data[c]);

        for(int i=0; i<mergeData.size(); i++)
        {
            if(i == 0)
            {
                result = mergeData[i];
            }
            else
            {
                vector<string> newStr;
                for(int j=0; j<result.size(); j++)
                    for(int k=0; k<mergeData.size(); k++)
                        newStr.push_back(to_string(result[j]) + to_string(mergeData[k]));
                result = newStr;
            }
        }

        return result;
    }
};
*/