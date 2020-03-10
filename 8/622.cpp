#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


class Solution {
public:
    /**
     * @param stones: a list of stones' positions in sorted ascending order
     * @return: true if the frog is able to cross the river or false
     */
    bool canCross(vector<int> &stones) {
        // write your code here
        int len = stones.size();
        map<int, set<int>> m;//存放可以到达的位置以及由哪一位置到达现在的位置
        m[1].insert(0);
        for (int i = 1; i < len; ++i)
        {
            if (i == 1)      //对于i==1,stepLength=1,则1（位置）可以到2,3位置,就在m[2],m[3]中添加1
            {
                if (stones[i] == 1)
                {
                    m[2].insert(1);
                    m[3].insert(1);
                }
                else
                    return false;
            }
            else
            {
                //m中没有stones[i],说明没有位置可以到达stones[i]位置
                if (m.find(stones[i]) == m.end())
                {
                    return false;
                }
                else
                {
                    //num表示上一步跳num个单位,遍历set,得到目前位置可以跳的所有单位
                    //长度(num-1,num,num+1),计算可以跳到的位置pos,并在其set中添加现在的位置
                    for (auto c : m[stones[i]])
                    {
                        for (int j = -1; j <= 1; ++j)
                        {
                            int num = stones[i] - c + j;
                            if (num > 0)
                            {
                                m[stones[i] + num].insert(stones[i]);
                            }
                        }
                    }
                }
            }
        }
        return true;
    }
};
