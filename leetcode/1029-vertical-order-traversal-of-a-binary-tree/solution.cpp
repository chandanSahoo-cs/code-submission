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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==nullptr) return {};

        vector<vector<int>>vp;
        queue<pair<pair<int,int>,TreeNode*>>q;

        q.push({{0,0},root});

        while(!q.empty()){
            auto [c,r] = q.front().first;
            TreeNode* node = q.front().second;
            q.pop();

            vp.push_back({c,r,node->val});

            if(node->left) q.push({{c-1,r+1},node->left});
            if(node->right) q.push({{c+1,r+1},node->right});
        }

        sort(vp.begin(),vp.end());

        vector<vector<int>>ans;

        for(int i=0;i<vp.size();){
            auto v = vp[i];
            int currPtr = v[0];

            vector<int>keep;
            while(i<vp.size() && currPtr==vp[i][0]){
                keep.push_back(vp[i][2]);
                i++;
            }

            ans.push_back(keep);
        }

        return ans;
    }
};
