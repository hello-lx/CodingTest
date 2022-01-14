"""
Definition for a multi tree node.
class MultiTreeNode(object):
    def __init__(self, x):
        self.val = x
        children = [] # children is a list of MultiTreeNode
"""


class Solution:
    # @param {MultiTreeNode} root the root of k-ary tree
    # @return {int} the length of the longest consecutive sequence path
    def longestConsecutive3(self, root):
        # Write your code here
        self.longest = 0
        
        self.dfs(root)
        
        return self.longest
        
    def dfs(self, root):
        
        increasing, decreasing = 1, 1 
        
        for node in root.children:
            up, down = self.dfs(node)
            if node.val + 1 == root.val:
                increasing = max(increasing, up + 1)
            if node.val - 1 == root.val:
                decreasing = max(decreasing, down + 1)
                
        self.longest = max(self.longest, increasing + decreasing - 1)
        
        return increasing, decreasing