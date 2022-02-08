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



class Solution {
public:
    /**
     * @param s: A string
     * @return: Whether the string is a valid palindrome
     */
    bool isPalindrome(string &s) {
        // write your code here
        int start = 0;
        int end = s.size() - 1;
        while(start < end)
        {
            while(!isalnum(s[end]) && end >=0)
            {
                end--;
            }
            while(!isalnum(s[start]) && start < s.size())
            {
                start++;
            }
            if(tolower(s[start]) == tolower(s[end]))
            {
                start++;
                end--;
            }
            else return false;
        }
        return true;
    }
};
