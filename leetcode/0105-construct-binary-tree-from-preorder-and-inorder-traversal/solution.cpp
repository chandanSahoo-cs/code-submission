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
    
    TreeNode* build(unordered_map<int,int>&mp, vector<int>&preorder,int pStart,int pEnd, vector<int>&inorder, int iStart, int iEnd){
        if(iStart>iEnd){
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[pStart]);

        int idx = mp[preorder[pStart]];
        
        int numleft =  idx-iStart;

        root->left = build(mp,preorder,pStart+1,pStart+numleft,inorder,iStart, idx-1);
        root->right = build(mp,preorder,pStart+numleft+1,pEnd,inorder,idx+1,iEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        TreeNode* root = build(mp,preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return root;
    }
};
