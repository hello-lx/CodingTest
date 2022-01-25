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
    vector<vector<int>> levelOrderBottom(TreeNode * root) {
        vector<vector<int>> res;
        if(!root)   return res;

        queue<TreeNode*> q;
        q.emplace(root);

        function<void(queue<TreeNode*>)> fun = [&](queue<TreeNode*> data){
            if(data.empty())    return;
            int size = data.size();
            vector<int> temp;
            while(size-- > 0){
                TreeNode* node = data.front();
                data.pop();
                temp.emplace_back(node->val);
                if(node->left)  data.emplace(node->left);
                if(node->right) data.emplace(node->right);
            }
            fun(data);
            res.emplace_back(temp);
        };
        fun(q);
        
        return res;
    }
};

