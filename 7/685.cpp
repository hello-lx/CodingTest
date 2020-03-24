#include <vector>
#include <set>
#include <queue>
using namespace std;


/*
 我们运用二个容器以及一个队列（这里用队列的原因是这里需要找出第一个唯一的数字），这两个容器中第一个的作用就是存储所有出现的数字，第二个容器是存储出现多次的数字，队列是用来存储出现一次的数字。每次出现一个数字，我们首先检查其是否出现在第一个容器中，如果没有出现则将其添加进第一个容器以及队列中，反之如果出现了，首先我们可以将其加入第二个容器，然后看队列中是否存在这个数字，如果存在就将其删除，反之不操作。
 */

class Solution {
public:
    /*
     * @param : a continuous stream of numbers
     * @param : a number
     * @return: returns the first unique number
     */
    int firstUniqueNumber(vector<int> nums, int number) {
        // Write your code here
        if(nums.empty()){
            return -1;
        }
        set<int>dic;//存储出现过的数字
        set<int>set;//存储出现多次的数字
        queue<int>que;//存储出现一次的数字
        bool flag=true;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=number){
                if(dic.find(nums[i])==dic.end()){
                    que.push(nums[i]);
                    dic.insert(nums[i]);
                }else{
                    set.insert(nums[i]);
                    // 用set去除在queue中重复的数字
                    while(!que.empty()&&set.find(que.front())!=set.end()){
                        que.pop();
                    }
                }
            }else{
                flag=false;
                if(dic.find(nums[i])==dic.end()){
                    que.push(nums[i]);
                }else{
                    if(que.front()==nums[i]){
                        que.pop();
                    }
                }
                break;
            }
        }
        if(flag){
            return -1;
        }else{
            return que.empty()?-1:que.front();
        }
    }
};
