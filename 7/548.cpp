/* Python3
import collections

class Solution:
    """
    @param nums1: an integer array
    @param nums2: an integer array
    @return: an integer array
    """
    def intersection(self, nums1, nums2):
        # write your code here
        a, b = map(collections.Counter, (nums1, nums2))
        return list((a & b).elements())

*/

/*
def intersect(nums1, nums2):
  """
  :type nums1: List[int]
  :type nums2: List[int]
  :rtype: List[int]
  """
  res = []
  for k in nums1:
    if k in nums2:
      res.append(k)
      nums2.remove(k)
  return res
*/
