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
    /**
     * @param root: A Tree
     * @return: Level order a list of lists of integer
     */
    vector<vector<int>> levelOrder(TreeNode * root) {
        // write your code here
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> Q;
        Q.push(root);
        
        function<void(queue<TreeNode*>)> func = [&](queue<TreeNode*> data){
            if(data.empty()) return;

            int size = data.size();
            vector<int> temp;
            while(size-- > 0)
            {
                auto node = data.front();
                data.pop();
                temp.push_back(node->val);
                if(node->left) data.push(node->left);
                if(node->right) data.push(node->right);
            }
            
            res.push_back(temp);
            func(data);
        };

        func(Q);

        return res;
    }
};