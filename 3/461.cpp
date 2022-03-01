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

/*
    算法：快速选择算法
    最容易想到的就是直接排序，返回第k大的值。时间复杂度是O(nlogn)，这里提供O(n)的解法。

    这题其实是快速排序算法的变体，通过快速排序算法的partition步骤，可以将小于pivot的值划分到pivot左边，大于pivot的值划分到pivot右边，
        所以可以直接得到pivot的rank。从而缩小范围继续找第k大的值。

    partition步骤：

    令left = start，right = end，pivot = nums[left]。
    当nums[left] < pivot时，left指针向右移动。
    当nums[right] > pivot时，right指针向左移动。
    交换两个位置的值，right指针左移，left指针右移。
    直到两指针相遇，否则回到第2步。
    每次partition后根据pivot的位置，寻找下一个搜索的范围。

    复杂度分析
    设数组长度为n

    时间复杂度O(n)
    对一个数组进行partition的时间复杂度为O(n)。
    分治，选择一边继续进行partition。
    所以总的复杂度为T(n) = T(n / 2) + O(n)，总时间复杂度依然为O(n)。
    空间复杂度O(1)
    只需要快速选择游标的O(1)额外空间。
*/

class Solution {
public:
    /**
     * @param k: An integer
     * @param nums: An integer array
     * @return: kth smallest element
     */
    int kthSmallest(int k, vector<int> &nums) {
        int n = nums.size();
        // 数组从0开始标号，要传k - 1
        return partition(nums, 0, n - 1, k - 1);
    }

    int partition(vector<int>& nums, int start, int end, int k) {
        int left = start, right = end;
        int pivot = nums[left];
        
        while (left <= right) 
        {
            while (left <= right and nums[left] < pivot) {
                left++;
            }
            while (left <= right and nums[right] > pivot) {
                right--;
            }
            if (left <= right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }
        }
        
        // 如果第 k 小在左侧，搜索右边的范围，否则搜索右侧。
        if (k <= right) {
            return partition(nums, start, right, k);
        }
        if (k >= left) {
            return partition(nums, left, end, k);
        }
        return nums[k];
    }
    };
