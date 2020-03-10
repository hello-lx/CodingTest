#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 *  python3
    def jump(self, A):
        # write your code here
        start=end=step=0
        while end<len(A)-1:
            start,end=end+1,max(i+A[i] for i in range(start,end+1))
            step+=1
        return step
*/


#include <algorithm>

class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: An integer
     */
    int jump(vector<int> &A) {
        // write your code here
        int n = A.size();
        if(n==0) return 0;
        
        int start=0, end=0, step=0;
        while(end<n-1){
            // find the maximum value
            int m = -10000;
            for(int i=start; i<end+1; i++){
                m = max(m, A[i]+i);
            }
            
            start = end+1;
            end = m;
            step += 1;
        }
        
        return step;
    }
};
