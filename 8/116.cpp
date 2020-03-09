#include <vector>
using namespace std;


/*  python3
  
 class Solution:
    """
    @param A: A list of integers
    @return: A boolean
    """
    def canJump(self, A):
        # write your code here
                # write your code here
        n = len(A)
        f = [False] *n
        for i in range(n):
            if i == 0:
                f[0] = True
                continue
                for j in range(i):
                    #如果j位置可以到达，且j位置跳跃<=A[j]步就可以到达位置i
                    if f[j] == True and A[j]+j >= i:
                        f[i] = True
                        break
                
        return f[n-1]
  
 */


class Solution {
public:
    /**
     * @param A: A list of integers
     * @return: A boolean
     */
    bool canJump(vector<int> &A) {
        // write your code here
        int n = A.size();
        vector<bool> result(n, false);
        
        for(int i=0; i<n; i++){
            if(i==0){
                result[0] = true;
                continue;
            }
            for(int j=0; j < i; j++){
                if(result[j] == true && A[j]+j >= i){
                    result[i] = true;
                    break;
                }
            }
        }
        
        return result[n-1];
    }
};
