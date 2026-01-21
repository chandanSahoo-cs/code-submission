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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;

        queue<pair<long long,TreeNode*>>q;
        q.push({0,root});

        long long ans = 0;

        while(!q.empty()){
            int sz = q.size();
            long long base,mx;

            for(int i=0;i<sz;i++){
                auto [ind,node] = q.front();
                q.pop();
                if(i==0){
                    base = ind;
                }
                if(i==sz-1){
                    mx = ind;
                }

                if(node->left) q.push({2*(ind-base)+1,node->left});
                if(node->right) q.push({2*(ind-base)+2,node->right});
            }

            ans = max(mx-base+1,ans);
        }

        return ans;
    }
};
