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
    bool traverse(TreeNode* root, TreeNode* subRoot){
        queue<pair<TreeNode*, TreeNode*>>qu;
        qu.push({root,subRoot});

        while(!qu.empty()){
            auto [p,q] = qu.front();
            qu.pop();

            if(!p || !q){
                if((!p && q) || (p && !q)) return false;
            }else{
                if(p->val!=q->val) return false;
                qu.push({p->left,q->left});
                qu.push({p->right,q->right});
            } 
        }

        return true;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(traverse(curr,subRoot)) return true;
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }

        return false;
    }
};
