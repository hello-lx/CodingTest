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

// Definition of TreeNode:
class TreeNode {
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    /**
     * @param root the root of binary tree
     * @return a lists of linked list
     */
    vector<ListNode*> binaryTreeToLists(TreeNode* root) {
        // Write your code here
        vector<ListNode*> ans;
        
        if(!root) return ans;

        queue<vector<TreeNode*>> Q;
        vector<TreeNode*> level1 = {root};
        Q.push(level1);
        while(!Q.empty())
        {
            vector<TreeNode*> temp, level = Q.front();
            Q.pop();
            ListNode *start = new ListNode(level[0]->val);
            if(level[0]->left) temp.push_back(level[0]->left);
            if(level[0]->right) temp.push_back(level[0]->right);

            for(int i=1; i<level.size(); i++)
            {
                ListNode *node = start;
                while(node->next) node = node->next;
                node->next = new ListNode(level[i]->val);

                if(level[i]->left) temp.push_back(level[i]->left);
                if(level[i]->right) temp.push_back(level[i]->right);
            }
            
            ans.push_back(start);
            if(!temp.empty()) Q.push(temp);
        }

        return ans;
    }
};
