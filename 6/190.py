# https://blog.csdn.net/guoziqing506/article/details/51787763

'''
    1. 找到比他小且最近的值a
    2. 进行交换
    3. 再对a后面的值进行排序
'''

class Solution:
    """
    @param nums: An array of integers
    @return: nothing
    """
    def nextPermutation(self, nums):
        n = len(nums)
        if n == 0 or n == 1:
            return
        right_index = n - 1
        pivot = 0
        # 从右边起找第一个（i - 1, i），使得nums[i] > nums[i - 1]
        while right_index >= 0:
            if right_index - 1 >= 0 and nums[right_index] > nums[right_index - 1]:
                # 将找到的i - 1记为pivot
                pivot = right_index - 1
                break
            elif right_index == 0:
                pivot = right_index - 1
                break
            else:
                right_index -= 1
        # 若pivot < 0，则说明这是最后一个排列了，就需要将nums改为最小的排列
        if pivot < 0:
            nums.sort()
        else:
            right_index = n - 1
            # 从右边起，找第一个大于nums[pivot]的数，并将这个数与nums[pivot]交换
            while right_index >= 0:
                if nums[right_index] > nums[pivot]:
                    nums[right_index], nums[pivot] = nums[pivot], nums[right_index]
                    break
                else:
                    right_index -= 1
            # 将此时pivot之后的部分数组翻转（其实也就是重新排序）
            left = pivot + 1
            right = n - 1
            while left < right:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
                right -= 1
        # write your code here