#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @param arrs: the arrays
     * @return: the number of the intersection of the arrays
     */
    int intersectionOfArrays(vector<vector<int>> &arrs) {
        // write your code here
        int ret = 0;
        set<int> myset[arrs.size()];
        for(int i = 0; i < arrs.size(); i++)
        {
            //myset[i] = set(arrs[i].begin(), arrs[i].end());
            for(int j = 0; j < arrs[i].size(); j++)
            {
                myset[i].insert(arrs[i][j]);
            }
        }
        
        for(int i = 0; i < arrs[0].size(); i++)
        {
            bool tmp = true;
            for(int j = 1; j < arrs.size(); j++)
            {
                if((myset[j].find(arrs[0][i])) == myset[j].end())
                {
                    tmp = false;
                    break;
                }
            }
            if(tmp == true)
            {
                ret++;
                cout<<arrs[0][i]<<endl;
            }
                
        }
        
        
        return ret;
    }
};
