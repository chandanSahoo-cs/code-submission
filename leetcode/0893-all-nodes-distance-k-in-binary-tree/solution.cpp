/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    int assignDist(TreeNode* root, TreeNode* target, int k, vector<int>&mark){
        if(root==nullptr){
            return -1; 
        }
        if(root==target){
            mark[root->val]=k;
            return max(k-1,-1);
        }

        int left = assignDist(root->left, target, k,mark);
        int right = assignDist(root->right, target, k,mark);
        mark[root->val]=max(left,right);
        return max(max(left,right)-1,-1);
    }

    void traverse(TreeNode* root, TreeNode* target, int k, vector<int>&ans,vector<int>&mark){
        if(root==nullptr){
            return;
        }

        if(mark[root->val]!=-1){
            if(mark[root->val]==0){
                ans.push_back(root->val);
            }
            traverse(root->left, target,mark[root->val]-1,ans,mark);
            traverse(root->right, target,mark[root->val]-1,ans,mark);
        }else{
            if(k==0){
                ans.push_back(root->val);
            }
            traverse(root->left,target,max(k-1,-1),ans,mark);
            traverse(root->right,target,max(k-1,-1),ans,mark);
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>mark(501,-1);

        assignDist(root,target,k,mark);
        vector<int>ans;
        traverse(root,target,-1,ans,mark);
        return ans;
    }
};
