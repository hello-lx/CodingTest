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

#include<numeric>
class Solution {
public:
    /**
     * @param pages: an array of integers
     * @param k: An integer
     * @return: an integer
     */
    int copyBooks(vector<int> &pages, int k) 
    {
        if(pages.size() == 0)
            return 0;
        if(k == 0)
            return -1;
        
        int len = pages.size();
        int max_page = 0;
        for(int i = 0; i < len; ++i)
        {
            max_page = max(pages[i], max_page);
        }
        int left = max_page;
        int right = accumulate(pages.begin(), pages.end(), 0);
        int mid;
        while(left + 1 < right)
        {
            mid = (int)((left + right) / 2);
            // 如果返回的人数小于指定的人数 说明时间还可以更短
            if(check(pages, mid) <= k)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        if(check(pages,left) <= k)
            return left;
        
        return right;        
    }
    int check(vector<int> &pages, int mid)//返回需要的人数
    {
        int person = 1;
        int sum = 0;
        for(auto & data : pages)
        {
            if((sum + data) > mid)
            {
                person++;
                sum = 0;
            }
            sum += data;
        }
        return person;
    }
};
