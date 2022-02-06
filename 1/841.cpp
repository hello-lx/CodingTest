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


struct Compare{
    bool operator() (string &a, string &b){
        return a.size() >= b.size();
    }
};


class Solution {
public:
    string stringReplace(vector<string> &a, vector<string> &b, string &s) {
        unordered_map<string, string> A2B;
        for(int i=0; i<a.size(); i++) A2B[a[i]] = b[i];
        sort(a.begin(), a.end(), Compare());

        int l=0, r=s.size()-1;
        while(l <= r)
        {
            for(int i=0; i<a.size(); i++)
            {
                if(r-l+1 < a[i].size()) continue;
                string str = s.substr(l, (int)a[i].size());
                if(str == a[i])
                {
                    s.replace(l, (int)str.size(), A2B[str]);
                    l = l + a[i].size() - 1;
                    break;
                }
            }
            l++;
        }

        return s;
    }
};
