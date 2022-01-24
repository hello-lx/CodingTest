#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;

#define INT_MIN -99999999999
#define INT_MAX 99999999999



class Solution {
public:
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        if(start == end)
            return 1;
        int n = start.size();
        if(n < 1 || n != end.size())
            return 0;
        std::queue<string> Q;
        Q.push(start);
        dict.erase(start);
        int length = 2;
        while(!Q.empty())
        {
            int size = Q.size();
            for(int i = 0; i < size; i++)
            {
                string word = Q.front();    
                Q.pop();
                for(int i = 0; i < n; i++)
                {
                    char oldchar = word[i];  
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        // if(c == oldchar)
                        //     continue;
                        word[i] = c;
                        if (word == end)
                            return length;
                        if(dict.find(word) != dict.end())
                        {
                            Q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[i] = oldchar;
                }
            }
            length++;
        }
        return 0;
    }
};