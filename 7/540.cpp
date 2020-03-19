/* Python3
class ZigzagIterator:
    """
    @param: v1: A 1d vector
    @param: v2: A 1d vector
    """
    def __init__(self, v1, v2):
        # do intialization if necessary
        self.vec = []
        n1, n2 = len(v1), len(v2)
        for i in range(max(n1, n2)):
            if i < n1:
                self.vec.append(v1[i])
            if i < n2:
                self.vec.append(v2[i])
            
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


# Your ZigzagIterator object will be instantiated and called as such:
# solution, result = ZigzagIterator(v1, v2), []
# while solution.hasNext(): result.append(solution.next())
# Output result
*/


/* Java
public class ZigzagIterator {
//     * @param v1 v2 two 1d vectors
    public Iterator<Integer> it1;
    public Iterator<Integer> it2;
    public int count;
    public ZigzagIterator(List<Integer> v1, List<Integer> v2) {
        // initialize your data structure here.
        this.it1 = v1.iterator();
        this.it2 = v2.iterator();
        count = 0;
    }

    public int next() {
        // Write your code here
        count++;
        if ((count % 2 == 1 && it1.hasNext()) || (!it2.hasNext())) {
            return it1.next();
        } else if ((count % 2 == 0 && it2.hasNext()) || (!it1.hasNext())) {
            return it2.next();
        }
        return -1;
    }

    public boolean hasNext() {
        // Write your code here
        return it1.hasNext() || it2.hasNext();
    }
}

*/
