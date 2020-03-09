#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @param n: a positive integer
     * @return: An integer
     */
     int getMaxSqrt(int n){
         float x = sqrt(double(n));
         int a = floor(x);
         return a;
     }
     
    int numSquares(int n) {
        // write your code here
        int temp = n;
        vector<int> ar;
    	vector<vector<int>> arr;
    	int maxSqrt = getMaxSqrt(n);
    	int sum = 0;
    	int  j = 0;
    	int MaxSqrt = maxSqrt;
    	for(int i = maxSqrt; i > 0; i--)
    	{
    		while(temp > 0)
    		{
    			ar.push_back(maxSqrt * maxSqrt);
    			temp -= maxSqrt * maxSqrt;
    			maxSqrt = getMaxSqrt(temp);
    		}
    		arr.push_back(ar);
    		ar.clear();
    		maxSqrt = --MaxSqrt;
    		temp = n;
    	}
    	
    	int maxSize = arr[0].size();
    	for(int i=0; i<arr.size(); i++)
    	    if(arr[i].size() < maxSize) maxSize = arr[i].size();
	    
	    return maxSize;
    }
};
