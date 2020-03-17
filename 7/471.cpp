#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<functional>
using namespace std;

struct cmp{
    bool operator()(pair<int, string> a, pair<int, string> b)
    {
        if (a.first != b.first)
        {
            return a.first < b.first;
        }
        else
            return a.second>b.second;
    }
};

class Solution {
public:
    /**
     * @param words: an array of string
     * @param k: An integer
     * @return: an array of string
     */
    vector<string> topKFrequentWords(vector<string> &words, int k) {
        // write your code here
        if (words.empty())
            return words;
        vector<string> res;
        if (k <= 0)
            return res;
        //规范k的值
        if (k > words.size())
            k = words.size();
        map<string, int> m;//存放字符串及其出现次数
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> que;//构建符合题意的堆
        for (auto c : words)
            m[c]++;
        //将所有的<字符串,出现次数>放入堆中
        for (auto t : m)
        {
            pair<int, string> temp = make_pair(t.second, t.first);
            que.push(temp);
        }
        //求堆顶的前k个值
        for (int i = 0; i < k; ++i)
        {
            res.push_back(que.top().second);
            que.pop();
        }
        return res;        
        
    }
};
