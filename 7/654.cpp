/*  sparse
class Solution {
public:
//      * @param A: a sparse matrix
//      * @param B: a sparse matrix
//      * @return: the result of A * B
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        // write your code here
        int n = A.size();
        int t = A[0].size();
        int m = B[0].size();
        vector<vector<int>> C(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < t; k++) {
                if (A[i][k] == 0) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }
};
*/


/* directly
#include <vector>
using namespace std;

class Solution {
public:
//      * @param A: a sparse matrix
//      * @param B: a sparse matrix
//      * @return: the result of A * B
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        // write your code here
        int n = A.size();
        int t = A[0].size();
        int m = B[0].size();
        vector<vector<int>> C(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sum = 0;
                for (int k = 0; k < t; k++) {
                    sum += A[i][k] * B[k][j];
                }
                C[i][j] = sum;
            }
        }
        return C;
    }
};
*/
