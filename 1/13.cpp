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
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        // Write your code here
        if(source.size() < target.size()) return -1;
        if(target == "") return 0;

        for(int i=0; i<source.size(); i++)
            if(source[i]==target[0] && i+target.size()<=source.size() && source.substr(i, target.size()) == target)
                return i;

        return -1;
    }
};