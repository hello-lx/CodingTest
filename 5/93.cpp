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
#include <function>
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
     * @param root: The root of binary tree.
     * @return: True if this Binary tree is Balanced, or false.
     */

    bool isBalanced(TreeNode * root) 
    {
        // write your code here
        function<int(TreeNode*)>dfs;
        dfs=[&dfs](TreeNode* root)->int{
            if(root){
                int depthl=dfs(root->left),depth2;
                if(depthl<0||(depth2=dfs(root->right))<0||
                    depth2>depthl+1||depthl>depth2+1)
                    return -1;
                return max(depthl,depth2)+1;
            }
            return 0;
        };
        
        return dfs(root)>=0;
    }
};

