/**
 * 1.用prefix存储前缀对应的字符串，空串是所有字符串的前缀。
 * 2.storage存储已选择的字符串，注意回溯。
 * 3.第k层生成第k列长度为k的字符串，作为后续dfs串的前缀（剪枝）。
 * 4.后缀合法判断。
 * 5.注意dfs出口和words的判空。
 */

class Solution {
public:
    /*
     * @param words: a set of words without duplicates
     * @return: all word squares
    */
    vector<vector<string> > result;
    map<string, vector<string> >prefix;
    vector<string> storage; 
    int num;
    vector<vector<string> > wordSquares(vector<string> &words) 
    {
        // write your code here
        if(words.size() == 0) 
        {
            return result;
        }
        //存储前缀
        for(auto str: words) {
            string ret="";
            prefix[ret].push_back(str);
            for(auto c: str) {
                ret += c;
                prefix[ret].push_back(str);
            }
        }

        num=words[0].size();
        dfs(0);
        return result;
    }

    bool check(int cur, string str) {
        for(int i = cur + 1; i < num; ++i) {
            string pre="";
            for(int j = 0; j < cur; ++j) {
                pre += storage[j][i];
            }
            pre += str[i];
            if(prefix[pre].size() == 0) {
                return false;
            }
        }
        return true;
    }

    void dfs(int cur) {
        if(cur == num) {
            result.push_back(storage);
            return ;
        }
        string pre="";
        //剪枝
        for(auto str: storage) {
            pre += str[cur];
        }
        for(auto str: prefix[pre]) {
            if(!check(cur, str)) {
                continue;
            } 
            storage.push_back(str);
            dfs(cur+1);
            storage.pop_back();
        }
    }
};