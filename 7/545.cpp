/* Python3  
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
    @param: k: An integer
    """
    def __init__(self, k):
        # do intialization if necessary
        self.k = k
        self.lst = []

    """
    @param: num: Number to be added
    @return: nothing
    """
    def add(self, num):
        # write your code here
        self.lst.append(num)
        low, high = 0, len(self.lst)-1
        quickSort(self.lst, low, high)

    """
    @return: Top k element
    """
    def topk(self):
        # write your code here
        if len(self.lst) < self.k:
            return self.lst
        else:
            return self.lst[:self.k]
*/
