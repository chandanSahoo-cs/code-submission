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
    int maxLevelSum(TreeNode* root) {
        int level = 0;
        int sum = INT_MIN;

        queue<TreeNode*>q;
        q.push(root);

        int currLevel=1;

        while(!q.empty()){
            int sz = q.size();
            
            int currSum = 0;

            for(int i=0;i<sz;i++){
                auto node = q.front();
                q.pop();

                currSum +=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            if(currSum>sum){
                level = currLevel;
                sum = currSum;
            }  

            currLevel++;

        }

        return level;
    }
};
