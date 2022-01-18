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
private:
    string get_str(vector<vector<int>>& v) {
        string str = "";
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                str.push_back('0' + v[i][j]);
        return str;
    }
    int get_idx(vector<vector<int>>& v) {
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (v[i][j] == 0)
                    return i * 3 + j;
        return -1;
    }
    
public:
    int minMoveStep(vector<vector<int>> &init_state, vector<vector<int>> &final_state) 
    {
        string init_str = get_str(init_state);
        string final_str = get_str(final_state);
        if (init_str.compare(final_str) == 0)
            return 0;
        unordered_set<string> visited;
        queue<pair<string, int>> que;
        que.push({init_str, get_idx(init_state)});
        visited.insert(init_str);
        int lvl = 1;
        int ds[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while (que.size()) {
            int size = que.size();
            while (size--) {
                auto p = que.front();
                que.pop();
                string str = p.first;
                int r = p.second / 3;
                int c = p.second % 3;
                for (auto & d : ds) {
                    int x = r + d[0];
                    int y = c + d[1];
                    if (x >= 0 && x < 3 && y >= 0 && y < 3) {
                        int idx = x * 3 + y;
                        swap(str[p.second], str[idx]);
                        if (visited.find(str) == visited.end()) {
                            if (str.compare(final_str) == 0)
                                return lvl;
                            visited.insert(str);
                            que.push({str, idx});
                        }
                        swap(str[p.second], str[idx]);
                    }
                }
            }
            lvl++;
        }
        
        return -1;
    }
};