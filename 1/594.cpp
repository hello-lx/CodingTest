#include <iostream>
#include <list>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <list>
#include <queue>
#include <stack>
using namespace std;

#define INT_MIN -99999999999
#define INT_MAX 99999999999


/*

字符串Hash可以通俗的理解为，把一个字符串转换为一个整数。

如果我们通过某种方法，将字符串转换为一个整数，就可以快速的判断两个字符串是否相同。

当然如果有不同的两个字符串同时Hash到一个整数，这样就比较麻烦了，所以我们希望构造这个Hash函数使得他们成为一个单射。

算法思路
给定一个字符串S,对于一个字符c我们规定id(c)=c-'a'+1

hash[i]=(hash[i-1]*p+id(s[i]))%MOD

p和MOD均为质数，并且要尽量大

代码思路
计算target的hash值

计算source的hash值的过程中，依次计算每targetLen位的hash值。

   > 假设target长度为2，source为“abcd”

   >

   > hash("cd") = (hash("bc + d") - hash("b")*2 ) % BASE

复杂度分析
N表示字符串source长度，M表示字符串target长度

空间复杂度：O(1)

时间复杂度：O(N+M)
*/
