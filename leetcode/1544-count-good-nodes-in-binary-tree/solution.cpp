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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*,int>>q;
        q.push({root,-1e5});

        int cnt = 0;

        while(!q.empty()){
            auto[node,mx] = q.front();
            q.pop();

            cnt+=(node->val>=mx);
            
            mx = max(mx,node->val);

            if(node->left){
                q.push({node->left,mx});
            }

            if(node->right){
                q.push({node->right,mx});
            }
        }

        return cnt;
    }
};
