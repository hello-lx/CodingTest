#include <iostream>
#include <string>
using namespace std;

// blog:  https://blog.csdn.net/skyinmoon/article/details/73656924
/*
思路：首先要理解题意（想了好久才了解这个题目的意思）。这个说的是两个字符串要完全相等。意思就是判断是否能用含有'.'和"*"的字符串（我们称模式）来完全代替另一个字符串（我们称原串）。

（1）当原串为空时，显然只有模式串为空，或者具有“X*X*”的形式可以代替原串。

（2）当原串不为空，而模式串为空，显然false

（3）当原串不为空，模式串也不为空。

如果模式串第二个字符为"*"：如果模式串第一个字符与原串第一个字符相等，那么两者都可以进2；如果两者第一个字符不相等，那么只能模式串进2；

如果模式串第二个字符不为"*"：如果模式串第一个字符与原串第一个字符相等，那都可以进1；否则必然不能代替原串，返回false.
*/

class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "." and "*"
     * @return: A boolean
     */
    bool isMatch(string s, string p) 
        // write your code here
    {
        if (s.length() == 0){
            // s串匹配完合法的情况只有p为空，或是 "X*X*"的形式
            if (p.length() & 1) return false;
            else {
                for (int i = 1; i < p.length(); i += 2) {
                    if (p[i] != '*') return false;
                }
            }
            return true;
        }
        if (p.length() == 0) return false;
        if (p.length() > 1 && p[1] == '*') {
            if (p[0] == '.' || s[0] == p[0]) {
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            } else return isMatch(s, p.substr(2));
        } else {
            if (p[0] == '.' || s[0] == p[0]) {
                return isMatch(s.substr(1), p.substr(1));
            } else return false;
        }
    }
};

int main(int argc, char* argv[])
{
    string s = "1234";
    cout << s.substr(2) << endl;
    return 0;
}
