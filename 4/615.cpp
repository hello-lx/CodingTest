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

/*
1. 建立課程-先修課程 清單
2. 每抓到一堂先修課，就要把那堂課的入度+1
3. 找出入度為 0 的課程，從這個課程開始
4. 檢查是不是上過這堂課，上過的話就代表有環狀，當下return false
5. 沒上過的話加進去taken
6. 對這堂課的每一堂御修課的度數都-1，而且如果發現哪一堂預修課的入度為0的時候，放進Q
*/


class Solution {
public:
    /**
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: true if can finish all courses or false
     */
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        // write your code here
        vector<vector<int>> course_prerequisites(numCourses);
        vector<int> idg(numCourses);
        
        //建立課程-先修課程 清單
        //美抓到一堂先修課，就要把那堂課的入度+1
        for(auto a: prerequisites)
        {
            //       0                      1
            course_prerequisites[a.second].push_back(a.first);
            idg[a.first]++;
        }
        
        queue<int> Q;
        set<int> taken;
        
        //找出入度為 0 的課程，從這個課程開始
        for(int i = 0; i < numCourses; i++)
        {
            if(idg[i] == 0)
                Q.push(i);
        }
        
        while(!Q.empty())
        {
            int curr = Q.front();
            Q.pop();
            
            //檢查是不是上過這堂課，上過的話就代表有環狀，當下return false
            if(taken.find(curr) != taken.end())
                return false;
            //沒上過的話加進去taken
            taken.insert(curr);
            
            //對這堂課的每一堂御修課的度數都-1，而且如果發現哪一堂預修課的入度為0的時候，放進Q
            
            for(int i = 0; i < course_prerequisites[curr].size(); i++)
            {
                idg[course_prerequisites[curr][i]]--;
                if(idg[course_prerequisites[curr][i]] == 0)
                    Q.push(course_prerequisites[curr][i]);
            }  
        }
        return taken.size() == numCourses;
    }
};