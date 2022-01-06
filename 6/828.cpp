#include <map>
#include <string>

using namespace std;


class Solution {
public:
    /**
     * @param pattern: a string，denote pattern string
     * @param str: a string，denote matching string
     * @return: return an boolean，denote whether the pattern string and the matching string match or not
     */
    bool wordPattern (string &pattern, string &str) {
        // write your code here
        map<char, int>mp1;
        map<string, int>mp2;
        string tmp = "";
        int cnt = 0, now = 0;
        str += ' ';
        for (int i = 0; i < str.length(); ++i) 
        {
            if (str[i] == ' ') 
            {
                if (mp1.find (pattern[cnt]) == mp1.end() && mp2.find (tmp) == mp2.end()) 
                {
                    mp1[pattern[cnt]] = now;
                    mp2[tmp] = now++;
                } 
                else if (mp1.find (pattern[cnt]) != mp1.end() && mp2.find (tmp) != mp2.end()) 
                {
                    if (mp1[pattern[cnt]] != mp2[tmp]) 
                    {
                        return false;
                    }
                }
                else 
                {
                    return false;
                }
                tmp = "";
                cnt++;
            }
            else 
            {
                tmp += str[i];
            }
        }
        return true;
    }
};