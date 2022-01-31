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
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> &numbers, int target) {
        vector<vector<int>> res;
        int n=numbers.size();
        sort(numbers.begin(),numbers.end());
        for(int i1=0;i1<n-3;){
            for(int i2=i1+1;i2<n-2;){
                for(int diff,i3=i2+1,i4=n-1;i3<i4;)
                {
                    if((diff=numbers[i1]+numbers[i2]+numbers[i3]+numbers[i4]-target)==0)
                        res.push_back({numbers[i1],numbers[i2],numbers[i3],numbers[i4]});
                    if(diff<=0)
                        for(auto cur=numbers[i3];i3<i4&&numbers[++i3]==cur;);
                    if(diff>=0)
                        for(auto cur=numbers[i4];i3<i4&&numbers[--i4]==cur;);
                }
                for(auto cur=numbers[i2];i2<n-2&&numbers[++i2]==cur;);
            }
            for(auto cur=numbers[i1];i1<n-3&&numbers[++i1]==cur;);
        }
        return res;
    }
};

class Solution2 {
public:
    /**
     * @param numbers: Give an array
     * @param target: An integer
     * @return: Find all unique quadruplets in the array which gives the sum of zero
     */
    vector<vector<int>> fourSum(vector<int> &numbers, int target) {
        sort(numbers.begin(), numbers.end());
        vector<vector<int>> res;
        int n = numbers.size();
        if (n < 4) return res;
        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && numbers[i] == numbers[i - 1]) continue;
            if ((long long)numbers[i] + 3 * (long long)numbers[i + 1] > target) break;
            if ((long long)numbers[i] + 3 * (long long)numbers[n - 1] < target) continue;
            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && numbers[j] == numbers[j - 1]) continue;
                if ((long long)numbers[i] + (long long)numbers[j] + 2 * (long long)numbers[j + 1] > target) break;
                if ((long long)numbers[i] + (long long)numbers[j] + 2 * (long long)numbers[n - 1] < target) continue;

                int l = j + 1;
                int r = n - 1;
                long long sumij = numbers[i] + numbers[j];
                while(l < r) {
                    long long sum = sumij + numbers[l] + numbers[r];
                    if (sum == target) {
                        res.emplace_back(vector<int>{numbers[i], numbers[j], numbers[l], numbers[r]});
                        ++l;
                        --r;
                        while (l < r && numbers[l] == numbers[l - 1]) ++l;
                        while (l < r && numbers[r] == numbers[r + 1]) --r;
                    } else if (sum > target) {
                        --r;
                        while (l < r && numbers[r] == numbers[r + 1]) --r;
                    } else {
                        ++l;
                        while (l < r && numbers[l] == numbers[l - 1]) ++l;
                    }
                }
            }
        }
        return res;
    }
};
