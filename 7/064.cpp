/* Python3
class Solution:
    """
    @param: A: sorted integer array A which has m elements, but size of A is m+n
    @param: m: An integer
    @param: B: sorted integer array B which has n elements
    @param: n: An integer
    @return: nothing
    """
    def mergeSortedArray(self, A, m, B, n):
        # write your code here
        total = m+n-1
        while m > 0 and n > 0:
            if A[m-1] > B[n-1]:
                A[total] = A[m-1]
                m -= 1
            else:
                A[total] = B[n-1]
                n -= 1
            
            total -= 1
        #如果B没有扫描完，就将剩余的B全部放在A的前面
        if n > 0:
            A[:total+1] = B[:n]
        
        return A
*/

