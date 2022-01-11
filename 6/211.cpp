#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;


class Solution {
public:
    /**
     * @param A: a string
     * @param B: a string
     * @return: a boolean
     */
    bool Permutation(string &A, string &B) {
        // write your code here
        if(A.empty() && B.empty())
            return true;
        if(!A.empty() && B.empty() || A.empty() && !B.empty() || A.length() != B.length())
            return false;
        
        map<char, int> KeyA, KeyB;

        for(int i=0; i<A.length(); i++)
        {
            if(KeyA.find(A[i]) != KeyA.end())
                KeyA[A[i]] += 1;
            else
                KeyA[A[i]] = 1;
        }
        for(int i=0; i<B.length(); i++)
        {
            if(KeyB.find(B[i]) != KeyB.end())
                KeyB[B[i]] += 1;
            else
                KeyB[B[i]] = 1;
        }
        
        for(int i=0; i<A.length(); i++)
        {
            if(KeyA[A[i]] != KeyB[A[i]])
                return false;
        }

        return true;
    }
};
