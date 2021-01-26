/*  Python3
from heapq import heappop, heappush      
class Solution:     #heappop heappush 分别是弹出根节点和插入数据到堆中 操作
    """
    @param n: An integer
    @return: the nth prime number as description.
    """
    def nthUglyNumber(self, n):
        # write your code here
        result_set = [1]                      #初始结果集
        factor = [2,3,5]                      #3个素因子
        if n == 1:                            #如果n=1 直接返回结果 1
            return 1
        for _ in range(n):
            result = heappop(result_set)      #取出根节点
            for fac in factor:                #生成三个丑数
                tem = fac * result
                if tem not in result_set:     #若结果集中不存在该数就加入结果集
                    heappush(result_set, tem)
        return result
*/


#include <list>
using namespace std;

class Solution {
public:
    /**
     * @param n: An integer
     * @return: return a  integer as description.
     */
     void add(list<int> &vec, int n){
         for(auto it=vec.begin(); it!=vec.end(); it++)
            if(*it == n)
                return;
        vec.push_back(n);
     }
     
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        
        list<int> vec;
        vec.push_back(1);
        int result;
        for(int i=0; i<n; i++){
            result = vec.front();
            vec.pop_front();
            add(vec, result*2);
            add(vec, result*3);
            add(vec, result*5);
        }
        
        return result;
    }
};



int main(int argc, char** argv)
{
    
    return 0;
}