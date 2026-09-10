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

int total=0;
    pair<int,int>compute(TreeNode* curr){
        if(!curr) return {0,0};
        auto [lftCnt,lftSum] = compute(curr->left);
        
        auto [rghtCnt,rghtSum] = compute(curr->right);
        
        if(lftCnt+rghtCnt+1){
            int avg=(lftSum+rghtSum+curr->val)/(lftCnt+rghtCnt+1);
            total+=(avg==curr->val);
        }
        return {lftCnt+rghtCnt+1,lftSum+rghtSum  +curr->val};
    }
    
    
        
    int averageOfSubtree(TreeNode* root) {
        auto [cnt,sum] = compute(root);
        
        return total;
    }
};
