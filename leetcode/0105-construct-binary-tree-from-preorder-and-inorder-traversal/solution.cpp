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
    TreeNode* build(vector<int>& preorder, unordered_map<int,int>& inMp, int li, int l , int r){
        if(l>r) return nullptr;

        TreeNode* root = new TreeNode(preorder[l]);
        
        int idx = inMp[preorder[l]];

        root->left = build(preorder,inMp,li,l+1,l+idx-li);
        root->right = build(preorder,inMp,idx+1,l+idx-li+1,r);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int,int>inMp;

        for(int i=0;i<n;i++){
            inMp[inorder[i]] = i;
        }

        return build(preorder,inMp,0,0,n-1);    
    }
}; 
