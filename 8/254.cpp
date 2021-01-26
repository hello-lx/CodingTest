#include <iostream>
#include <vector>
#include <map>
#include <stdio.h>

using namespace std;

#define INT_MAX 9999999
#define max(a, b) ( ((a)<(b))? (b):(a) )
#define max(a, b) ( ((a)>(b))? (b):(a) )


// blog: https://blog.csdn.net/qq_43304321/article/details/104846135

int superEggDrop(int N, int K);
int helper(std::map<int, std::map<int, int> >& memo, int N, int K);

int main()
{
    int N = 100, K = 2;  // N: 楼层(floors)    K: 鸡蛋(eggs)
    cout << superEggDrop(N, K) << endl;
    return 0;
}

int superEggDrop(int N, int K)
{
    if(N==0 || K==1)  // 只有一层楼递归只需要一层楼；只有一个鸡蛋，需要N层楼(最坏情况层层向上扫描)
        return N;

    int res = INT_MAX;
    //对每一层进行一次遍历，相当于投每层楼的选择都试一遍,而每一次都有两种改变的情况（碎或没碎）
    for(int i=1; i <= N; i++)
    {
        //再次强调，这次的目的是找出最坏可能性的最小值
		//故具体在哪个楼层会碎是不确定的，必须都遍历，取最大(最坏情况）
        int temp = max(superEggDrop(i-1, K-1), superEggDrop(N-i, K)) + 1;
		res = min(temp, res);
    }

    return res;
}


// 第二种优化方案
int helper(std::map<int, std::map<int, int> >& memo, int N, int K)
{
    
}


class Solution {
public:
    /**
     * @param n: An integer
     * @return: The sum of a and b
     */
    int dropEggs(int n) {
        // write your code here
        int a=1;
        double sum=0;
        while(sum<n){
            sum += a;
            a++;
        }
        return a-1;
    }
};
