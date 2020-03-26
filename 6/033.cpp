#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    /*
    * @param n: The number of queens
    * @return: All distinct solutions
    */
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        // write your code here
        vector<int> solution;
        backTracing(solution, n);
        return ans;
    }
    
    void backTracing(vector<int> solution, int n) {
        if (solution.size() == n) {
            translate(solution);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isValid(solution, i)) {
                vector<int> temp;
                temp = solution;
                temp.push_back(i);
                backTracing(temp, n);
            }
        }
    }
    
    bool isValid(vector<int> solution, int p) {
        for (int i = 0; i < solution.size(); i++) {
            if (solution[i] == p) return false;
            if (abs((int)(solution.size() - i)) == abs((int)(p - solution[i]))) return false;
        }
        return true;
    }
    
    void translate(vector<int> solution) {
        vector<string> singleAns;
        for (int i = 0; i < solution.size(); i++) {
            string ansrow;
            for (int j = 0; j < solution.size(); j++) {
                if (solution[i] == j) ansrow += "Q";
                else ansrow += ".";
            }
            singleAns.push_back(ansrow);
        }
        ans.push_back(singleAns);
    }
};
