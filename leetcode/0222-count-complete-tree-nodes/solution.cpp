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
    int giveLen(TreeNode* root){
        if(root==nullptr) return 0;
        return 1+giveLen(root->left);
    }

    bool find(TreeNode* root, int curr, unordered_set<int>&parent,int key){
        if(curr==key) return true;

        int lft = 2*curr;
        int rght = 2*curr+1;

        if(root->left && parent.count(lft)){
            return find(root->left,lft,parent,key);
        }

        if(root->right && parent.count(rght)){
            return find(root->right,rght,parent,key);
        }

        return false;
    }

    int countNodes(TreeNode* root) {
        int len = giveLen(root);
        if(len==0) return 0;

        int nodes = (1<<(len-1))-1;

        int l = nodes+1, r = (1<<len)-1;

        int mx = l;

        while(l<=r){
            int m = l+(r-l)/2;
            int s = m;

            unordered_set<int>parent;

            while(s){
                parent.insert(s);
                s = s/2;
            }

            if(find(root,1,parent,m)){
                mx = m;
                l=m+1;
            }else r=m-1;
        }

        return mx;
    }
};
