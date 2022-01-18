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


int main(int argc, char** argv){

    // vector<string> keypad({"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"});
    // char *d = "8";
    // cout << *d << endl;

    vector<int> s = {1, 2, 3};
    string str;
    for(int i=0; i<s.size(); i++)
    {
        str.push_back('0' + s[i]);
        // str.push_back(s[i]);
    }

    cout << str << endl;

    return 0;
}




/* Python  mergeSort  O(N*log(N))  XXXXXXXXXXXX
def merge(left, right):
    result = []
    while len(left)>0 and len(right)>0:
        if left[0] > right[0]:
            result.append(left.pop(0))
        else:
            result.append(right.pop(0))
    
    result += left
    result += right
    
    return result
    
def mergeSort(nums):
    if len(nums) == 1:
        return nums
    mid = len(nums)//2
    left, right = nums[:mid], nums[mid:]
    return merge(mergeSort(left), mergeSort(right))
*/


/* Python quickSort  O(N)
# 左小右大函数，获取一个中值，左放小右放大函数
def partition(arr, low, high):       #参数：列表，列表的第一个索引0，最后一个索引值N
    """
    【左小右大函数】
    实现结果：提取列表中的最后一个元素为被比较值，≤该元素的值放在左边，＞该元素的值放在右边
    实现过程：≤最后一个元素的所有元素依次放在左边索引0~i的位置，然后将最后一个元素放在索引i的位置，实现结果
    arr: 列表
    low: arr的第一个索引：0
    high: arr的最后一个索引：high
    return: i，即被比较值所在的索引位置
    """
    i = low                                       # 最小元素索引
    pivot = arr[high]                             # 最后一个元素，我们把列表中的所有元素同它比较

    for j in range(low, high):                    #从第一个索引到倒数第二个索引
        if arr[j] <= pivot:                       #从第一个元素到倒数第二个元素依次判断是否≤最后一个元素
            arr[i], arr[j] = arr[j], arr[i]       #≤最后一个元素的所有元素依次放在左边索引0~i的位置
            i = i + 1
    arr[i], arr[high] = arr[high], arr[i]         #然后将最后一个元素放在索引i的位置，实现：该元素左边的都比它小，右边的都比它大的排序
    return (i)                                    #返回该元素的索引位置


# 快速排序函数
def quickSort(arr, low, high):
    if low < high:                                #如果列表有1个以上的元素
        pi = partition(arr, low, high)            #获取左小右大函数中的 被比较数所在的索引

        quickSort(arr, low, pi - 1)            #反复循环，左排序
        quickSort(arr, pi + 1, high)           #反复循环，右排序

arr = [10,22,78,3,12,9,1,11,33,2]
low = 0
high = len(arr)-1
quickSort(arr, low, high)
print(arr)

*/
