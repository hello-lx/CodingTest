#include <vector>
#include <iostream>
#include <set>
#include <map>
using namespace std;

/*
    此题实际上是680. split_string的follow up。
    可以用split string先获得所有切割字符串组合，然后从里面筛选所需的结果，但是如果n比较大会超时， 
    时间复杂度O（n!）， 因此必须要在获得结集的过程当中进行剪枝优化。
    一旦发现出现了不合理的组合就无需按照这个方向继续搜下去了，直接continue
    想了一下，有以下几种可能：

        1、切出来的字符串 > n
        2、切出来的字符串已经出现过了。
        3、切出来的字符串开头为0， 比如09，0

    这样下来求出的result， 随便取一个，把里面的数字求和，和 n * (n+1) / 2, 
    等差数列求和公式相减，就是所需结果。
*/


class Solution {
public:
    int findMissing2(int n, string &str) {
        vector<set<string>> result;
        set<string> path;
        dfs(result, path, 0, n, str);
        int sum = 0;
        for (auto iter = result[0].begin(); iter != result[0].end(); ++iter) 
            sum += stoi(*iter);

        return n * (n+1) / 2 - sum;
    }
    void dfs(vector<set<string>>& result, set<string>& path, int index, int n, string& str) {
        if (index == str.length() && path.size() == n - 1) {
            result.push_back(path);
            return;
        }
        for (int i = 1; i <= 2; ++i) 
        {
            if (index + i > str.length()) 
                break;
            string word = str.substr(index, i);
            if (word[0] == '0' || stoi(word) > n || path.find(word) != path.end()) 
                continue;
            path.insert(word);
            dfs(result, path, index + i, n, str);
            path.erase(word);
        }
    }
};