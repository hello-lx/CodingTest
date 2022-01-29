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
     * @param A: an integer array
     * @return: nothing
     */
    void sortIntegers2(vector<int> &A) {
        // write your code here
        qsort(A, 0, A.size() - 1);

        // mergeSort(A, 0, A.size() - 1);
    }


/*----------------------  quick sort  ----------------------*/
    void qsort(vector<int> &A, int left, int right) 
    {
        if (left >= right) return;

        int pivot_pos_after_partition = partition(A, left, right);
        qsort(A, left, pivot_pos_after_partition - 1);
        qsort(A, pivot_pos_after_partition + 1, right);
    }

    int partition(vector<int> &A, int left, int right) {
        int i, j, pivot_pos, pivot;

        pivot_pos = (left + right) / 2;
        pivot = A[pivot_pos];
        swap(&A[pivot_pos], &A[right]); // Hide pivot to right

        i = left - 1; j = right; // Opposite double pointer
        while (true) {
            while (A[++i] < pivot) {}
            while (i < j && A[--j] > pivot) {}

            if (i < j) {
                swap(&A[i], &A[j]);
            } else {
                    break;
            }
        }
        swap(&A[i], &A[right]); // Restore pivot

        pivot_pos = i;
        return pivot_pos;
    }

    void swap(int *left, int *right) {
        int tmp = *left;
        *left = *right;
        *right = tmp;    
    }
/*----------------------  quick sort  ----------------------*/


/*----------------------  merge sort  ----------------------*/
    //合并两个有序子序列
	void merge(vector<int>& A, int begin, int mid, int end, vector<int>& temp)
	{
		//第一个子序列起点和第二个子序列起点，以及temp数组起点
		int i = begin, j = mid + 1, k = 0;
		while (i <= mid && j <= end)
		{
			if (A[i] < A[j])
				temp[k++] = A[i++];
			else
				temp[k++] = A[j++];
		}
		//对剩余没合并的部分进行归并
		while (i <= mid)
			temp[k++] = A[i++];
		while (j <= end)
			temp[k++] = A[j++];
		//最后把temp里面存放的合并后为有序的左右序列倒回原数组a
	   //注意a的起点
		for (int i = 0; i < k; i++)
			A[begin + i] = temp[i];
	}

    //归并排序
	void mergeSort(vector<int>& A, int first, int last)
	{
		vector<int> temp(A.size(), 0);
		//迭代的实现是直接从最小子序列(含一个元素)开始往上两两合并
		int k = 1;//子序列长度
		int Last = 0;
		int First = 0;
		int mid = 0;
		while (k < last)
		{
			First = 0;
			//3.剩余大于等于两个子序列的元素个数
			while (First <= (last - 2 * k + 1))//加一的原因是因为下标从0算起
			{
				mid = First + k - 1;
				Last = First + 2 * k - 1;
				merge(A, First, mid, Last, temp);
				First += 2 * k;
			}
			//当剩下的没有合并处理过的元素数量不足2k，即无法构成两个子序列进行合并操作时，要分类处理
		   //1.剩下小于等于一个子序列的元素个数
			if (last - First <= k)
			{
				mid = First + (last - First) / 2;
				merge(A, First, mid, last, temp);
			}
			//2.剩下大于一个小于两个的子序列元素个数
			else
			{
				mid = First + k - 1;;
				merge(A, First, mid, last, temp);
			}
			k *= 2;
		}
		//说明此时是特殊奇数情况，数组末尾还单着一个元素没有于前面一个完整的子序列合并
		if (First == last)
		{
			merge(A, first, last - 1, last, temp);
		}
	}
/*----------------------  merge sort  ----------------------*/
};
