#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    /*
     * @param nums: A list of integers
     * @return: A list of integers that's previous permuation
     */
    vector<int> previousPermuation(vector<int> &nums) {
        // write your code here
        vector<int> result=nums;
        int n=nums.size();
        int t=-1;
        for (int i=n-2;i>=0;i--)
        {
            if (result[i]>result[i+1])
            {
                t=i;
                break;
            }
        }

        if (t==-1)
        {
            reverse(result.begin(),result.end());
        }
        else
        {
            int k;
            for (int j=n-1;j>t;j--)
            {
                if (result[j]<result[t])
                {
                    k=j;
                    break;
                }
            }
            swap(result[t],result[k]);
            reverse(result.begin()+t+1,result.end());
        }

        return result;
    }
};
