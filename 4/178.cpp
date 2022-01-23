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
    /**   并查集
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    map<int, int> p;
    int find(int x)
    {
        if (p[x] != x) 
            p[x] = find(p[x]);
            
        return p[x];
    }

    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.empty())
            return n == 1? true:false;
        for (int i = 0; i< n; i++)
        {
            p[i] = i;
        }

        for (auto node : edges)
        {
            if (find(node[0]) == find(node[1]))
            {
                return false;
            }

            p[find(node[0])] = find(node[1]);

            cout << node[0] << " -> " << node[1] << endl;
            for (int i = 0; i < n; i++)
                cout << i << " " << p[i] << endl;
            cout << endl;
        }

        std::set<int> res;
        for (int i = 0; i< n; i++)
        {
            res.insert(find(i));
        }
        if (res.size() != 1)
            return false;

        return true;
    }
};


int main(int argc, char const *argv[])
{
    // n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]  return true
    // n = 5 edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]  return false
    
    vector<vector<int>> v = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    int n = 5;
    Solution s;
    if(s.validTree(n, v))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}
