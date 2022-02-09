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
     * @param s: input string
     * @return: a string as the longest palindromic substring
     */
    string longestPalindrome(string &s) {
        // write your code here
        if(s.empty()) return "";

        int len = s.length();
        bool is_palindrome[len][len] = {false};
        is_palindrome[0][0] = true;
        for(int i=0; i<len; i++)
        {
            is_palindrome[i][i] = true;
            is_palindrome[i][i-1] = true;
        }

        int start = 0, longest = 1;
        for(int length=2; length <= len; length++){
            for(int i=0; i<=len-length; i++){
                int j=i+length-1;
                is_palindrome[i][j] = is_palindrome[i+1][j-1] && s[i] == s[j];

                if(is_palindrome[i][j] && length > longest){
                    start = i;
                    longest = length;
                }
            }
        }

        return s.substr(start, longest);
    }
};
