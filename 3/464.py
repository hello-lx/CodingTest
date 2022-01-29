'''

用3个class 封装的quick，merge 和 heap sort。
其中heap sort 应该是没问题的，但是会显示超时。

quick sort： 每次把按照pivot 分为左右两边，再递归处理左右两边，属于从大到小的partition， 一个tricky的点是，不需要分成 < 和 >=， 因为这样的话，如果有很多和pivot等值的元素会偏向一边，导致速度变慢。
merge sort： 同样分为左右两边，但是是从小到大，在merge之前，左右部分是都已经sorted。 merge的过程，是一个合并两个已经排序的数组的过程
heap sort：相对比较复杂，主要思想是通过把数组变成完全二叉树来达到log(n)的目的。heapify的做法是每次确保i 大于 left 和 right。在排序的时候，利用了每次把最大的元素，放到size-1的位置上，然后再把size --。 heapify之后的数组并不是排序好的数组，只是能够确保在log(n)的时间内，插入或者提取的最大数。
其实每个算法中间的一些细节都是可以单独拿出来用的，比如quick sort中的partition思想，merge sort的merge 数组本身就是一道题。heap sort可以借鉴的思想是利用数组的index 将其树化。
'''


class heapSort(object):
    def __init__(self,nums):
        self.A = nums
        self.size = len(nums)
        self.buildHeap()
        for i in range(self.size-1,-1,-1):
            self.A[0],self.A[i] = self.A[i],self.A[0]
            self.size -= 1
            self.heapify(0)
        
    def parent(self,i):
        return (i-1)/2
        
    def left(self,i):
        return i*2 + 1
        
    def right(self,i):
        return i*2 + 2
        
    def heapify(self,i):
        l,r = self.left(i),self.right(i)
        largest = i
        if l < self.size and self.A[l] > self.A[largest]:
            largest = l
        if r < self.size and self.A[r] > self.A[largest]:
            largest = r
        if largest != i:
            self.A[largest],self.A[i] = self.A[i],self.A[largest]
            self.heapify(largest)
    def buildHeap(self):
        for i in range(self.size-1,-1,-1):
            self.heapify(i)
            