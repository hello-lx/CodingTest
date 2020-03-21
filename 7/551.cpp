/* Python3
"""
This is the interface that allows for creating nested lists.
You should not implement it, or speculate about its implementation

class NestedInteger(object):
    def isInteger(self):
        # @return {boolean} True if this NestedInteger holds a single integer,
        # rather than a nested list.

    def getInteger(self):
        # @return {int} the single integer that this NestedInteger holds,
        # if it holds a single integer
        # Return None if this NestedInteger holds a nested list

    def getList(self):
        # @return {NestedInteger[]} the nested list that this NestedInteger holds,
        # if it holds a nested list
        # Return None if this NestedInteger holds a single integer
"""

def helper(nestedList, depth):
    if nestedList == None or len(nestedList) == 0:
        return 0
    
    s = 0
    for it in nestedList:
        if it.isInteger():
            s += it.getInteger() * depth
        else:
            s += helper(it.getList(), depth+1)
    
    return s

class Solution(object):
    # @param {NestedInteger[]} nestedList a list of NestedInteger Object
    
    # @return {int} an integer
    def depthSum(self, nestedList):
        # Write your code here
        return helper(nestedList, 1)
    
*/





/* Java
public class Solution {

    public int depthSum(List<NestedInteger> nestedList) {
        return helper(nestedList, 1);
    }

    public int helper(List<NestedInteger> nestedList, int depth){
        if (nestedList == null || nestedList.size() == 0)
            return 0;

        int sum = 0;
        for(NestedInteger ele : nestedList) {
            if (ele.isInteger()) {
                sum += ele.getInteger() * depth;
            } else {
                sum += helper(ele.getList(), depth + 1);
            }
        }

        return sum;
    }
*/
