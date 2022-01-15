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
        int longestConsecutive2(TreeNode * root) {
        // write your code here
		return dfs(root);
    }


	int dfs(TreeNode *root)
	{	
		this->ans = 0;
		__dfs(root);
		return this->ans + 1;
	}

	pair<int, int> __dfs(TreeNode *root)
	{
		if (root == nullptr) return {0, 0};

		int ins = 0, des = 0;

        auto check = [&](TreeNode *node, pair<int, int> &p) -> void
		{
			if (node == nullptr) return ;
			if (node->val - 1 == root->val) ins = max(ins, p.first + 1);
			else if (node->val + 1 == root->val) des = max(des, p.second + 1);
		};

		pair<int, int> l = __dfs(root->left); //first: 代表ins, second: 代表 des
		pair<int, int> r = __dfs(root->right);

		check(root->left,  l);
		check(root->right, r);

		this->ans = max(this->ans,  ins + des);
		return {ins, des};
	}

private:
	int ans;
};
