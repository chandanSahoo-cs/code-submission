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
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*>start,end;

        TreeNode* s = root;
        TreeNode* e = root;

        while(s!=nullptr){
            start.push(s);
            s=s->left;
        }

        while(e!=nullptr){
            end.push(e);
            e=e->right;
        }

        while(start.top()!= end.top()){
            int sum = start.top()->val+end.top()->val;
            if(sum==k) return true;
            else if(sum<k){
                TreeNode*top=start.top();
                start.pop();
                TreeNode*node=top->right;
                while(node!=nullptr){
                    start.push(node);
                    node=node->left;
                }
            }else{
                TreeNode*top=end.top();
                end.pop();
                TreeNode* node=top->left;
                while(node!=nullptr){
                    end.push(node);
                    node=node->right;
                }
            }
        }

        return false;
    }
};
