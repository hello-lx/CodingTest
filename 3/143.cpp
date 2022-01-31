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

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int val) {
       this->val = val;
       this->next = NULL;
    }
};

class Solution {
public:
    /**
     * @param colors: A list of integer
     * @param k: An integer
     * @return: nothing
     */
    void sortColors2(vector<int> &colors, int k) {
        // write your code here
        if(colors.size()==0) return;
        Sort(colors, 1, k, 0, colors.size()-1);
    }

    void Sort(vector<int> &colors, int color_start, int color_end, 
                            int index_start, int index_end)
    {
        if(color_start==color_end) return;
        int mid_color=(color_start+color_end)/2;
        int left=index_start, right=index_end;

        while(left<=right)
        {
            while(left<=right && colors[left]<=mid_color)
                left++;
            while(left<=right && colors[right]>mid_color)
                right--;
            if(left<=right)
            {
                int temp=colors[left];
                colors[left]=colors[right];
                colors[right]=temp;
                left++;
                right--;
            }
        }

        Sort(colors, color_start, mid_color, index_start, right);
        Sort(colors, mid_color+1, color_end, left, index_end);
    }
};
