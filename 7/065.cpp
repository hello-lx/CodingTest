/* Python3
class Solution:
    """
    @param: A: An integer array
    @param: B: An integer array
    @return: a double whose format is *.5 or *.0
    """
    def findMedianSortedArrays(self, A, B):
        # write your code here
        res = []
        na = len(A)
        nb = len(B)
        index_a = index_b = 0
        while index_a != na and index_b != nb:
            if A[index_a] < B[index_b]:
                res.append(A[index_a])
                index_a += 1
            else:
                res.append(B[index_b])
                index_b += 1
        
        res += A[index_a:]
        res += B[index_b:]
        
        if (na+nb) % 2 == 0:
            return float((res[(na+nb) // 2] + res[(na+nb)//2 - 1]) / 2)
        else:
            return float(res[(na+nb)//2])
*/

