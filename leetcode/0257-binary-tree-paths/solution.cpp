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
    vector<string>ans;
    void rec(TreeNode* root, string &s){
        int cnt=0;
        if(s.size()>0){
            s+="->";
            cnt+=2;
        }
        string t = to_string(root->val);
        cnt+=t.size();
        s+=t;

        if(!root->left && !root->right){
            ans.push_back(s);
        }

        if(root->left) rec(root->left,s);
        if(root->right) rec(root->right,s);

        while(cnt--){
            s.pop_back();
        }

        return ;
    }


    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        rec(root,s);

        return ans;
    }
};
