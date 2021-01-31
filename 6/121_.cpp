// https://www.cnblogs.com/bleopard/p/4066262.html

#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    std::vector<std::vector<std::string>> findLadders(std::string start, std::string end, std::unordered_set<std::string> &dict)
    {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> entry;

        entry.push_back(start);
        Find(start, end, dict, 0, result, entry);

        return result;
    }

private:
    void Find(std::string& start, const std::string& end, const std::unordered_set<std::string> &dict,
size_t positionToChange, std::vector<std::vector<std::string>>& result, std::vector<std::string>& entry)
    {
        //如果长度已经等于当前结果中的长度，再找出来肯定就
        //超过了，终止处理
        if(!result.empty() && entry.size() == result[0].size())
        {
            return;
        }

        for(size_t pos = positionToChange; pos < start.size(); ++pos)
        {
            char beforeChange = ' ';
            for(int i = 'a'; i <= 'z'; ++i)
            {
                //防止同字母替换
                if(start[pos] == i)
                {
                    continue;
                }
                beforeChange = start[pos];
                start[pos] = i;

                //用std::find的话
                /*
                 if(std::find(entry.begin(), entry.end(), start) != entry.end())
                 {
                      start[pos] = beforeChange;
                      continue;
                 }
                 */
                
                //如果单词已经用过的情况
                if(!used_.empty() && used_.count(start)!=0)
                {
                    start[pos] = beforeChange;
                    continue;
                }


                if(start == end)
                {
                    entry.push_back(start);

                    //只需要保存最短的序列
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

                    if(!entry.empty())
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

        return;
    }

    std::unordered_set<std::string> used_;
};

class Solution2 {
}

class Solution3 {
public:
    ~Solution()
    {
        for(auto iter = pool_.begin(); iter != pool_.end(); ++iter)
        {
            delete *iter;
        }
    }

    std::vector<std::vector<std::string> > findLadders(std::string start, std::string end, std::unordered_set<std::string> &dict)
    {
        std::queue<PathTag*> candidate;

        std::vector<std::vector<std::string>> result;
        std::unordered_set<std::string> usedWord;

        std::string currentString;
        bool foundShortest = false;
        size_t shortest = 0;
        size_t previousPathLen = 0;

        candidate.push(AllocatePathTag(nullptr, start, 1));

        while(!candidate.empty())
        {
            PathTag* current = candidate.front();
            currentString = current->value_;

            if(current->length_ != previousPathLen)
            {
                for(auto iter = usedWord.begin(); iter != usedWord.end(); ++iter)
                {
                    dict.erase(*iter);
                }
            }

            if(foundShortest && current->length_ >= shortest)
            {
                break;
            }


            for(size_t pos = 0; pos < start.size(); ++pos)
            {
                char beforeChange = ' ';
                for(int i = 'a'; i <= 'z'; ++i)
                {
                    beforeChange = currentString[pos];

                    if(beforeChange == i)
                    {
                        continue;
                    }

                    currentString[pos] = i;

                    if(dict.count(currentString) > 0)
                    {
                        usedWord.insert(currentString);

                        if(currentString == end)
                        {

                            GeneratePath(result, current, currentString);
                            foundShortest = true;
                            shortest = result.rbegin()->size();
                            continue;
                        }
                        else
                        {
                            candidate.push(AllocatePathTag(current, currentString, current->length_ + 1));
                        }
                    }
                    currentString[pos] = beforeChange;
                }
            }

            if(!candidate.empty())
            {
                previousPathLen = current->length_;

                candidate.pop();
            }
        }

        return result;
    }

private:
    struct PathTag
    {
        PathTag* parent_;
        std::string value_;
        int length_;

        PathTag(PathTag* parent, const std::string& value, int length) : parent_(parent), value_(value), length_(length)
        {

        }

    };

    PathTag* AllocatePathTag(PathTag* parent, const std::string& value, int length)
    {
        if(nextPoolPos_ >= pool_.size())
        {
            for(int i = 0; i < 100; ++i)
            {
                PathTag* newTag = new PathTag(nullptr, " ", 0);
                pool_.push_back(newTag);
            }
        }

        PathTag* toReturn = pool_[nextPoolPos_];
        toReturn->parent_ = parent;
        toReturn->value_ = value;
        toReturn->length_ = length;

        ++nextPoolPos_;

        return toReturn;
    }

    int nextPoolPos_;

    std::vector<PathTag*> pool_;

    void GeneratePath(std::vector<std::vector<std::string>>& result, PathTag* pathTag, const std::string& end)
    {
        std::vector<std::string> path;

        path.push_back(end);

        while(pathTag != nullptr)
        {
            path.push_back(pathTag->value_);

            pathTag = pathTag->parent_;
        }

        size_t left = 0;
        size_t right = path.size() - 1;

        while(left < right)
        {
            std::swap(path[left], path[right]);

            ++left;
            --right;
        }

        result.push_back(path);
    }

};


class Solution3 {
public:
    ~Solution()
    {
        for(auto iter = pool_.begin(); iter != pool_.end(); ++iter)
        {
            delete *iter;
        }
    }

    std::vector<std::vector<std::string> > findLadders(std::string start, std::string end, std::unordered_set<std::string> &dict)
    {
        nextPoolPos_ = 0;
        std::unordered_map<std::string, std::unordered_set<std::string>> adjacencyList;
        std::string word;

        for (auto iter = dict.begin(); iter != dict.end(); ++iter)
        {
            word = *iter;
            BuildAdjacencyList(word, adjacencyList, dict);
        }

        std::vector<std::vector<std::string>> result;
        std::queue<PathTag*> candidate;
        std::unordered_map<std::string, int> usedWord;

        std::string currentString;
        bool foundShortest = false;
        size_t shortest = 0;

        candidate.push(AllocatePathTag(nullptr, start, 1));

        while(!candidate.empty())
        {
            PathTag* current = candidate.front();

            if(foundShortest && current->length_ >= shortest)
            {
                break;
            }

            candidate.pop();

            auto adjacentIter = adjacencyList.find(current->value_);

            if(adjacentIter != adjacencyList.end())
            {
                for(auto iter = adjacentIter->second.begin(); iter != adjacentIter->second.end(); ++iter)
                {
                    if(*iter == end)
                    {
                        GeneratePath(result, current, *iter);
                        foundShortest = true;
                        shortest = result.rbegin()->size();
                        continue;
                    }

                    auto usedIter = usedWord.find(*iter);


                    if(usedIter != usedWord.end() && usedIter->second != current->length_ + 1)
                    {
                        continue;
                    }

                    usedWord[*iter] = current->length_ + 1;

                   candidate.push(AllocatePathTag(current, *iter, current->length_ + 1));
                }
            }
            else
            {
                continue;
            }

        }

        return result;
    }

private:
    struct PathTag
    {
        PathTag* parent_;
        std::string value_;
        int length_;

        PathTag(PathTag* parent, const std::string& value, int length) : parent_(parent), value_(value), length_(length)
        {
        }

    };

    PathTag* AllocatePathTag(PathTag* parent, const std::string& value, int length)
    {
        if(nextPoolPos_ >= pool_.size())
        {
            for(int i = 0; i < 100; ++i)
            {
                PathTag* newTag = new PathTag(nullptr, " ", 0);
                pool_.push_back(newTag);
            }
        }

        PathTag* toReturn = pool_[nextPoolPos_];
        toReturn->parent_ = parent;
        toReturn->value_ = value;
        toReturn->length_ = length;

        ++nextPoolPos_;

        return toReturn;
    }

    int nextPoolPos_;

    std::vector<PathTag*> pool_;

    void GeneratePath(std::vector<std::vector<std::string>>& result, PathTag* pathTag, const std::string& end)
    {
        std::vector<std::string> path;

        path.push_back(end);

        while(pathTag != nullptr)
        {
                        path.push_back(pathTag->value_);

            pathTag = pathTag->parent_;
                }

        size_t left = 0;
        size_t right = path.size() - 1;

        while(left < right)
        {
            std::swap(path[left], path[right]);

            ++left;
            --right;
        }

        result.push_back(path);
    }

    void BuildAdjacencyList(std::string& word, std::unordered_map<std::string, std::unordered_set<std::string>>& adjacencyList, const std::unordered_set<std::string>& dict)
    {
        std::string original = word;

        for(size_t pos = 0; pos < word.size(); ++pos)
        {
            char beforeChange = ' ';
            for(int i = 'a'; i <= 'z'; ++i)
            {
                beforeChange = word[pos];

                if(beforeChange == i)
                {
                    continue;
                }

                word[pos] = i;

                if(dict.count(word) > 0)
                {
                    auto iter = adjacencyList.find(original);
                    if(iter != adjacencyList.end())
                    {
                        iter->second.insert(word);
                    }
                    else
                    {
                        adjacencyList.insert(std::pair<std::string, std::unordered_set<std::string>>(original, std::unordered_set<std::string>()));
                        adjacencyList[original].insert(word);
                    }
                }

                word[pos] = beforeChange;
            }
        }

    }
};



int main(int argc, char** argv)
{
    
    return 0;
}