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
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        // write your code here
        vector<vector<int>> graph(numCourses);
        vector<int> deg(numCourses);
        vector<int> res;

        //根据给定参数构建树
        for(auto a : prerequisites)
        {
            graph[a.second].push_back(a.first);
            deg[a.first]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++)
        {
            if(deg[i]==0)
                q.push(i);
        }
        int taken=0;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            res.push_back(cur);
            taken++;
            for(int c:graph[cur])
            {
                deg[c]--;
                if(deg[c]==0)
                    q.push(c);
            }
        }

        if(taken==numCourses)
            return res;
        return {};
    }
};