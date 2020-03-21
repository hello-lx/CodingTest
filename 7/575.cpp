#include<iostream>
#include<string>
#include<stack>
using namespace std;
class Solution {
public:
    /*
    * @param s: an expression includes numbers, letters and brackets
    * @return: a string
    */
    string expressionExpand(string &s) {
        // write your code here
        if (s.empty())
            return s;
        string res;
        stack<char> sk;
        for (auto c : s)
        {
            if (c == ']')
            {

                string dup;
                while (sk.top() != '[')
                {
                    dup = sk.top()+dup;
                    sk.pop();
                }
                sk.pop();
                string num;
                while (!sk.empty()&&isdigit(sk.top()))
                {
                    num = sk.top() + num;
                    sk.pop();
                }
                int cnt = stoi(num);
                string str;
                while (cnt > 0)
                {
                    str+=dup;
                    --cnt;
                }
                for (auto c : str)
                    sk.push(c);
            }
            else
            {
                sk.push(c);
            }
        }
        while (!sk.empty())
        {
            res = sk.top() + res;
            sk.pop();
        }
        return res;
    }
};
