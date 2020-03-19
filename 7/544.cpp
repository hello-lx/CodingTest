/* Python3  qucikSort  log(N)
def partition(arr, low, high):
    pivot = arr[high]
    i = low
    for j in range(low, high):
        if arr[j] >= pivot:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
    arr[i], arr[high] = arr[high], arr[i]
    
    return i

def quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi-1)
        quickSort(arr, pi+1, high)

class Solution:
    """
    @param nums: an integer array
    @param k: An integer
    @return: the top k largest numbers in array
    """
    
    def topk(self, nums, k):
        # write your code here
        # nums = sorted(nums, reverse=True)
        low, high = 0, len(nums)-1
        quickSort(nums, low, high)
        return nums[:k]
*/



/* Python  mergeSort  N*log(N)  XXXXXXXXXXXX
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

class Solution:
    """
    @param nums: an integer array
    @param k: An integer
    @return: the top k largest numbers in array
    """
    
    def topk(self, nums, k):
        # write your code here
        nums_sort = mergeSort(nums)
        return nums_sort[:k]
        
*/
