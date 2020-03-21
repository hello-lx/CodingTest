#include <queue>
using namespace std;

class MovingAverage {
public:
    /*
    * @param size: An integer
    */ 
    MovingAverage(int size) {
        // do intialization if necessary
        m_size=size;
    }

    /*
     * @param val: An integer
     * @return:  
     */
    double next(int val) {
        // write your code here
        result.push(val);
        int len=result.size();
        if(len<=m_size)
        {
            sum+=val;
            return sum/len;
        }
        else
        {
            sum-=result.front();
            sum+=result.back();
            result.pop();
            return sum/m_size;
        }
    }
private:
    int m_size;
    queue<int> result;
    double sum;
};


/* Python3
class MovingAverage:
    """
    @param: size: An integer
    """
    def __init__(self, size):
        # do intialization if necessary
        self.size = size
        self.nums = []
        self.sum = 0

    """
    @param: val: An integer
    @return:  
    """
    def next(self, val):
        # write your code here
        self.nums.append(val)
        if len(self.nums) <= self.size:
            self.sum += val
            return sum(self.nums) / len(self.nums)
        else:
            self.sum -= self.nums[0]
            self.sum += self.nums[-1]
            self.nums.pop(0)
            return self.sum/self.size
*/
