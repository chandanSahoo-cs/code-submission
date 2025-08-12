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
    void traverse(vector<vector<int>>&ans,queue<TreeNode*>&q){
        if(q.front()==nullptr) return;

        bool flag=true;
        
        while(!q.empty()){
            vector<TreeNode*>temp;
            vector<int>val;

            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }

            for(auto ele:temp){
                if(ele->left!=nullptr) q.push(ele->left);
                if(ele->right!=nullptr) q.push(ele->right);
                val.push_back(ele->val);
            }

            if(flag){
                ans.push_back(val);
            }else{
                reverse(val.begin(),val.end());
                ans.push_back(val);
            }

            flag=!flag;
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);

        traverse(ans,q);

        return ans;
    }
};
