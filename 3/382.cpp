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
     * @param S: A list of integers
     * @return: An integer
     */
    int triangleCount(vector<int> &S) {
        // write your code here
        if(S.size()<3) return 0;
        int cnt=0;
        sort(S.begin(), S.end());
        for(int i=2; i<S.size(); i++)
        {
            int l=0, r=i-1;
            while(l<r)
            {
                int sum=S[l]+S[r];
                if(sum>S[i])
                {
                    cnt+=r-l;
                    r--;
                }
                else
                    l++;
            }
        }
        return cnt;    
    }
};
