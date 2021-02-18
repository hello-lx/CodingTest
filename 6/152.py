class Solution:
    """
    @param n: Given the range of numbers
    @param k: Given the numbers of combinations
    @return: All the combinations of k numbers out of 1..n
    """
    def combine(self, n, k):
        # write your code here
        def backtrack(inputData, k, auxiliary, result):
            if len(auxiliary) == k:
                result.append(auxiliary[:])
                return
            for index in range(len(inputData)):
                if len(auxiliary) >= 1:
                    if inputData[index] < auxiliary[-1]:
                        continue
                auxiliary.append(inputData[index])
                backtrack(inputData[: index] + inputData[index + 1 :], k, auxiliary, result)
                auxiliary.pop()
        inputData = [index for index in range(1, n + 1)]
        result = []
        auxiliary = []
        backtrack(inputData, k, auxiliary, result)
        return result
