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
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode * root) 
    {
        // bfs to serialize
        if(root == nullptr)
        {
            return "";
        }

        string res;
        queue<TreeNode*> q;
        q.push(root);
        res.append(to_string(root->val));
        res.push_back(',');

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(cur->left){
                q.push(cur->left);
                res.append(to_string(cur->left->val));
                res.push_back(',');
            }
            else{
                res.append("#");
                res.push_back(',');
            }

            if(cur->right){
                q.push(cur->right);
                res.append(to_string(cur->right->val));
                res.push_back(',');
            }
            else{
                res.append("#");
                res.push_back(',');
            }
        }

        return res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode * deserialize(string &data) {
        if(data.size() < 1){
            return nullptr;
        }

        vector<int> dataArray = convertData(data);
        int iter = 0;
        TreeNode* root = new TreeNode(dataArray[iter++]);

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* cur = q.front();
            q.pop();

            if(dataArray[iter] != INT_MIN){
                cur->left = new TreeNode(dataArray[iter]);
                q.push(cur->left);
            }
            iter++;

            if(dataArray[iter] != INT_MIN){
                cur->right = new TreeNode(dataArray[iter]);
                q.push(cur->right);
            }
            iter++;
        }

        return root;
    }

    vector<int> convertData(string data){
        string word;
        vector<int> res;

        for(int i = 0; i < data.size(); i++){
            if(isdigit(data[i])){
                word.push_back(data[i]);
            }
            else if(data[i] == '#'){
                res.push_back(INT_MIN);
                word.clear();
            }
            else{
                if(!word.empty()){
                    res.push_back(stoi(word));
                }
                word.clear();
            }
        }

        return res;
    }
};


int main(int argc, char** argv)
{
    
    return 0;
}