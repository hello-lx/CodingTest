#include <string>
#include <map>

using namespace std;
/**   1、先从pattern中取一个字符c；
 *    2、然后从string中挨个遍历获取剩余的字符，然后比较；
 *    3、若比较到最后模式串idx和字符串idx相等，则返回true，否则false；
 */


class Solution {
public:
    /**
     * @param pattern: a string,denote pattern string
     * @param str: a string, denote matching string
     * @return: a boolean
     */
    bool wordPatternMatch(string &pattern, string &str) {
        return match(pattern, 0, str, 0);
    }

private:
    bool match(const string& pattern, int pidx, const string& str, int sidx) {
        if (sidx == str.size() && pidx == pattern.size()) {
            return true;
        }
        if (sidx == str.size() || pidx == pattern.size()) {
            return false;
        }
        
        char c = pattern[pidx];
        int remain_len = str.size()-sidx;
        if (dict.count(c)) 
        {
            const string& expected = dict[c];
            if (remain_len < expected.size() || str.compare(sidx, expected.size(), expected)) 
            {
                return false;
            } 
            else 
            {
                return match(pattern, pidx+1, str, sidx+expected.size());
            }
        }

        for (int l = 1; l <= remain_len; ++l) 
        {
            string word = str.substr(sidx, l);
            if (used.count(word)) 
            {
                continue;
            }
            dict[c] = word;
            used.insert(word);
            if (match(pattern, pidx+1, str, sidx+l)) 
            {
                return true;
            }
            used.erase(word);
            dict.erase(c);
        }

        return false;
    }
    
private:
    unordered_map<char, string> dict;
    unordered_set<string> used;
};