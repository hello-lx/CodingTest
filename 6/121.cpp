#include <vector>
#include <string>
#include <unordered_set>
using namespace std;


class Solution {
public:
    std::vector<std::vector<std::string>> findLadders(std::string start, std::string end, std::unordered_set<std::string> &dict)
    {
        vector<vector<string>> result;
        vector<string> entry;

        entry.push_back(start);

        Find(start, end, dict, 0, result, end);
    }

private:
    unordered_set<string> used_;

    void Find(string &start, const string &end, const unordered_set<string> &dict,
    size_t positionToChange, vector<vector<string>> &result, vector<string> &entry)
    {
        //如果长度已经等于当前结果中的长度，再找出来肯定就超过了，终止处理
        if(!result.empty() && entry.size() == result[0].size())
            return;
        
        for(size_t pos=positionToChange; pos<start.size(); pos++)
        {
            char beforeChange = ' ';
            for(int i='a'; i<='z'; i++)
            {
                // 跳过相同字母
                if(start[pos] == i)
                    continue;

                beforeChange = start[pos];
                start[pos] = i;

                // 如果单词已经用过的情况
                if(!used_.empty() && used_.count(start)!=0)
                {
                    start[pos] = beforeChange;
                    continue;
                }

                if(start == end)
                {
                    entry.push_back(start);

                    if(!result.empty())
                    {
                        if(entry.size() < result[0].size())
                        {
                            result.clear();
                            result.push_back(entry);
                        }
                        else if(entry.size() == result[0].size())
                        {
                            result.push_back(entry);
                        }
                    }
                    else
                    {
                        result.push_back(entry);
                    }
                    //完成一个序列，把前面加入的end弹出
                    entry.pop_back();
                    return;
                }

                if(dict.find(start) != dict.end())
                {
                    entry.push_back(start);
                    used_.insert(start);
                    Find(start, end, dict, 0, result, entry);
                    used_.erase(*entry.rbegin());
                    entry.pop_back();

                    if(!empty.empty())
                    {
                        start = *entry.rbegin();
                    }
                    else
                    {
                        start[pos] = beforeChange;
                    }
                }
                else
                {
                    start[pos] = beforeChange;
                }
            }
        }
    }
};