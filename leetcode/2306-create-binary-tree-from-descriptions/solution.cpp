/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>node;
        unordered_map<int,bool>hasParent;

        for(auto ele:descriptions){
            TreeNode* parent = nullptr;
            TreeNode* child = nullptr;

            if(!node.count(ele[0])){
                node[ele[0]] = new TreeNode(ele[0]);
            }
            if(!node.count(ele[1])){
                node[ele[1]] = new TreeNode(ele[1]);
            }

            parent = node[ele[0]];
            child = node[ele[1]];

            hasParent[ele[1]] = true;
            if(!hasParent.count(ele[0])) hasParent[ele[0]] = false;

            if(ele[2]){
                parent->left = child;
            }else parent->right = child;
        }

        for(auto [key,value]:hasParent){
            if(!value) return node[key];
        }

        return nullptr;
    }
};
