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

class TreeNode {
public:
    int val;     
    TreeNode *left, *right;

    TreeNode(int val) {
        this->val = val;
        this->left = this->right = NULL;
    }
};


/*
分析：
1、对于每一个节点，它都有可能是一个path的结尾，也可能是一个path的开头，还可能是一个path的中间点
2、对于递归（DFS），sentencesA可以包含所有父节点的信息，sentencesB可以包含子节点处理后的信息
3、在深度遍历中，找一条path的过程是从上往下的，即找到一条path总是发生在更里层、更下层的节点访问中

综合上面的分析，可以得出算法的初步内容：
1、在sentenceA的部分，判断当前节点是不是一条path的结尾（需要获取已经遍历过的父节点列表anc_nodes，
    以及其val的和值sum。）
2、将当前节点加入anc_nodes, 当前val加入sum，传递给递归调用，处理当前节点可能是path的中间点的情况。
3、处理当前节点是一个path的开头的情况，则需要：
    3.1 如果以当前节点为结尾的path符合要求，即val = target，则构建一个只含当前节点的列表nodes，
        将它放入结果集中。
    3.2 如果以当前节点为开头，以其子孙节点为结尾，则需要深度遍历。将nodes和val传递给递归调用
*/

class Solution {
public:
    /*
     * @param root: the root of binary tree
     * @param target: An integer
     * @return: all valid paths
     */
    vector<vector<int>> binaryTreePathSum2(TreeNode * root, int target) {
        // write your code here
        vector<vector<int>> res;
        if(root == NULL){
            return res;
        }
        //开始深度遍历二叉树，对根节点这一层单独进行处理
        vector<int> nodes = {root->val};
        if(root->val == target){
            res.push_back(nodes);
        }
        traversal(res, root->left, target, root->val, nodes, true);
        traversal(res, root->right, target, root->val, nodes, true);
        return res;
    }

    void traversal(vector<vector<int>> &res, TreeNode *node, int t, int sum, vector<int> &anc_nodes, bool from_now_on){
        // 递归的最下层
        if(node == NULL){
            return;
        }

        //对祖先传过来的链条负责
        anc_nodes.push_back(node->val);
        if(sum + node->val == t){
            res.push_back(anc_nodes);
        }
        //顺着祖先继续向下
        traversal(res, node->left, t, sum+node->val, anc_nodes, from_now_on);
        traversal(res, node->right, t, sum+node->val, anc_nodes, from_now_on);
        anc_nodes.pop_back(); //保证函数退出时上一层的anc_nodes不包含本层的节点

        //对从本节点开始的链条负责   
        if(from_now_on){           
            vector<int> nodes = {node->val};  
            if(node->val == t){
                res.push_back(nodes);
            }
            //以本节点为根向下
            traversal(res, node->left, t, node->val, nodes, false);
            traversal(res, node->right, t, node->val, nodes, false);
        }
    }
};