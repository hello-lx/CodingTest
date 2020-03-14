#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


class Solution {
public:
    /**
     * @param num: A list of integers
     * @return: An integer
     */
    int longestConsecutive(vector<int> &num) {
        // write your code here
		if(num.size() == 0)
		{
			return 0;
		}
		map<int,int>m;
		vector<int>::iterator it1 = num.begin();
		vector<int>::iterator it2 = num.end();
 
		for(;it1 != it2;it1++)//把数组中的元素插入到map中去 value = 1
		{
			if(m.find(*it1) == m.end())
			{
				m.insert(pair<int,int>(*it1,1));
			}
		}
 
		int maxlen = 0;
		int len = 0;
 
		for(it1 = num.begin();it1 != it2;it1++)//从头到尾的遍历
		{
			if(m[*it1] > 0)//value > 0
			{
				int index = *it1;//index记录当前值
				len = 0;
				for(;m.find(index) != m.end();++len,m[index++] = -1);
				//我们定义一个值 index，index开始不停自增1，如果每次自增1后 index 依然可以在map中找到值，就说明数组中存在k，k+1, k+2...这样的连续序列
				//此时len为一个连续数组长度
				for(index = *it1 - 1;m.find(index) != m.end();++len,m[index--] = -1);
				//接着，index 开始不停自减1，直到map里找不到这样的index，这样就找出了k-1, k-2, ...这样的连续序列
				if(len > maxlen)
				{
					maxlen = len;
				}
			}
		}
		return maxlen;
    }
};
