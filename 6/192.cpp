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

class Solution {
public:

    bool isMatch(string &s, string &p) {
        
        if (s.empty() && p.empty()) {
            return true;
        }
        
        if (p.empty()) {
            return false;
        }
        
        if (s.empty()) {
            for (int i = 0; i < p.size(); ++i) {
                if (p[i] != '*') {
                    return false;
                }
            }
        }
        
        bool DP[s.size()][p.size()];
        
        for (int i = 0; i < s.size(); ++i) {
            for (int j = 0; j < p.size(); ++j) {
                DP[i][j] = false;
            }
        }
        
        for (int i = s.size() - 1; i >= 0; --i) {
            bool visitChar = false;
            for (int j = p.size() - 1; j >= 0; --j) {
                if (j == p.size() - 1) {
                    if (p[j] == '*') {
                        DP[i][j] = true;
                    }
                    if (i == s.size() - 1 && (s[i] == p[j] || p[j] == '?')) {
                        DP[i][j] = true;
                        visitChar = true;
                    }
                    continue;
                }
                if (DP[i][j + 1] == true) {
                    if (p[j] == '*') {
                        DP[i][j] = true;
                    }
                    else if (!visitChar && (s[i] == p[j] || p[j] == '?')) {
                        visitChar = true;
                        DP[i][j] = true;
                    }
                }
                if (i == s.size() - 1) {
                    continue;
                }
                if (DP[i + 1][j] == true) {
                    if (p[j] == '*') {
                        DP[i][j] = true;
                    }
                }
                if (DP[i + 1][j + 1] == true) {
                    if (s[i] == p[j]) {
                        visitChar = true;
                        DP[i][j] = true;
                    }
                    if (p[j] == '?') {
                        visitChar = true;
                        DP[i][j] = true;
                    }
                    if (p[j] == '*') {
                        DP[i][j] = true;
                    }
                }
            }
        }
        
        return DP[0][0];
    }
};
