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

/*
    分别将两个点到根节点路径上的节点，依次放入数组，同向双指针，
    第一次出现不同节点则是开始分叉的节点，其上一指针处则为LCA。
*/

class ParentTreeNode {
public:
    int val;
    ParentTreeNode *parent, *left, *right;
};


class Solution {
public:
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    ParentTreeNode * lowestCommonAncestorII(ParentTreeNode * root, ParentTreeNode * A, ParentTreeNode * B) {
        // write your code here
        if (!root) return nullptr;

        vector<ParentTreeNode*> a_path = path2root(A);
        vector<ParentTreeNode*> b_path = path2root(B);

        int a_pos = a_path.size() - 1;
        int b_pos = b_path.size() - 1;
        while (a_pos >= 0 && b_pos >= 0 && a_path[a_pos] == b_path[b_pos]) {
            a_pos--;
            b_pos--;
        }
    
        int ancestor_pos = a_pos + 1;
        if (ancestor_pos < a_path.size()) return a_path[ancestor_pos];

        return nullptr;
    }

    vector<ParentTreeNode*> path2root(ParentTreeNode *node) {
        vector<ParentTreeNode*> path;

        ParentTreeNode *tmp = node;
        while (tmp) {
            path.push_back(tmp);
            tmp = tmp->parent;
        }

        return path;
    }
};