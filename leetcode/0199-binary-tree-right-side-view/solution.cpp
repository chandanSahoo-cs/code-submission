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
    void traverse(TreeNode* node,int row, int col, map<int ,pair<int,int>>&mp){
        if(node==nullptr) return;
        if(mp.find(row)==mp.end()) mp[row]={node->val,col};
        // else if(mp[row].second<col) mp[row]={node->val,col};
        traverse(node->right,row+1,col+1,mp);
        traverse(node->left,row+1,col-1,mp);
    }

    vector<int> rightSideView(TreeNode* root) {
        map<int,pair<int,int>>mp;
        traverse(root,0,0,mp);

        vector<int>ans;

        for(auto ele:mp){
            ans.push_back(ele.second.first);
        }

        return ans;
    }
};
