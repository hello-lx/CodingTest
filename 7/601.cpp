/* Python3
class Vector2D(object):

    # @param vec2d {List[List[int]]}
    def __init__(self, vec2d):
        # Initialize your data structure here
        self.vec1d = []
        self.count = 0
        for item in vec2d:
            if isinstance(item, int):
                self.vec1d.append(item)
            else:
                self.vec1d += item

    # @return {int} a next element
    def next(self):
        # Write your code here
        if self.hasNext():
            item = self.vec1d[self.count]
            self.count += 1
            return item

    # @return {boolean} true if it has next element
    # or false
    def hasNext(self):
        # Write your code here
        return self.count < len(self.vec1d)

# Your Vector2D object will be instantiated and called as such:
# i, v = Vector2D(vec2d), []
# while i.hasNext(): v.append(i.next())
*/
