#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    /*
     * @param A: Given an integer array
     * @return: nothing
     */
    void heapify(vector<int> &A) {
        // write your code here
        int n = A.size();
        if (n == 0) {
            return;
        }
        for (int i = n / 2; i >= 1; i--) {
            int k = i;
            int j = 2 * i;
            while (j <= n) {
                if (j < n && A[j - 1] > A[j]) {
                    j++;
                }
                if (A[k - 1] > A[j - 1]) {
                    swap(A[k - 1], A[j - 1]);
                    k = j;
                    j = 2 * k;
                } else {
                    break;
                }
            }
        }
    }
};
