/* Python3
class ZigzagIterator2:
    """
    @param: vecs: a list of 1d vectors
    """
    def __init__(self, vecs):
        # do intialization if necessary
        self.vec = []
        
        max_num = len(vecs[0])
        for i in range(len(vecs)):
            if len(vecs[i]) > max_num: max_num = len(vecs[i])
        
        for col in range(max_num):
            for i in range(len(vecs)):
                if col >= len(vecs[i]): continue
                self.vec.append(vecs[i][col])
        
        self.it = iter(self.vec)
        self.count = 0

    """
    @return: An integer
    """
    def next(self):
        # write your code here
        if self.hasNext():
            self.count += 1
            return next(self.it)

    """
    @return: True if has next
    """
    def hasNext(self):
        # write your code here
        return self.count < len(self.vec)

# Your ZigzagIterator2 object will be instantiated and called as such:
# solution, result = ZigzagIterator2(vecs), []
# while solution.hasNext(): result.append(solution.next())
# Output result
*/
