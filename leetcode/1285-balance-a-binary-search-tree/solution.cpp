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
    TreeNode* build(vector<int>&a, int l, int r){
        if(l>r) return nullptr;

        int mid = (l+r)/2;

        TreeNode* parent = new TreeNode(a[mid]);
        parent->left = build(a,l,mid-1);
        parent->right = build(a,mid+1,r);

        return parent;
    }

    TreeNode* balanceBST(TreeNode* root) {
        TreeNode* curr = root;

        vector<int>ans;

        while(curr){
            if(curr->left==nullptr){
                ans.push_back(curr->val);
                curr = curr->right;
            }else{
                TreeNode* temp = curr->left;

                while(temp->right && temp->right!=curr){
                    temp = temp->right;
                }

                if(temp->right==nullptr){
                    temp->right = curr;
                    curr = curr->left;
                }else{
                    ans.push_back(curr->val);
                    temp->right = nullptr;
                    curr = curr->right;
                }
            }
        }

        for(auto ele:ans){
            cout<<ele<<" ";
        }

        return build(ans,0,ans.size()-1);
    }
};
