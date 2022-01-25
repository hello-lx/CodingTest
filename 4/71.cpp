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

class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode * root) {
        vector<vector<int>> res;
        if(!root)   return res;

        stack<TreeNode*> stk1, stk2;
        stk1.emplace(root);

        while(!stk1.empty() || !stk2.empty()){
            vector<int> temp;
            if(!stk1.empty()){
                while(!stk1.empty()){
                    TreeNode* node = stk1.top();
                    stk1.pop();
                    temp.emplace_back(node->val);
                    if(node->left)  stk2.emplace(node->left);
                    if(node->right) stk2.emplace(node->right);
                }
            }
            else{
                while(!stk2.empty()){
                    TreeNode* node = stk2.top();
                    stk2.pop();
                    temp.emplace_back(node->val);
                    if(node->right) stk1.emplace(node->right);
                    if(node->left)  stk1.emplace(node->left);
                }
            }
            res.emplace_back(temp);
        }
        return res;
    }
};
