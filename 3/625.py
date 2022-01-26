class Solution:
    """
    @param nums: an integer array
    @param low: An integer
    @param high: An integer
    @return: nothing
    """
    def partition2(self, nums, low, high):
        if not nums:
            return 
        
        start, end = 0, len(nums) - 1
        while start <= end:
            while start <= end and nums[start] < low:
                start += 1
            while start <= end and nums[end] >= low:
                end -= 1
            if start <= end:
                nums[start], nums[end] = nums[end], nums[start]
                start += 1
                end -= 1
        
        # the ending point will be like
        # end | | start
        # example: low = 2, high = 3
        # 1,1,4,3,2,3,4,2
        #   j i
        while start < len(nums) - 1 and nums[start] <= low:
            start += 1
        

        start, end = start,  len(nums) - 1
        while start <= end:
            while start <= end and nums[start] <= high:
                start += 1
            while start <= end and nums[end] > high:
                end -= 1
            if start <= end:
                nums[start], nums[end] = nums[end], nums[start]
                start += 1
                end -= 1
        
        return