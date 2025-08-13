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
    void traverse(TreeNode* node, map<int,vector<pair<int,int>>> &store,int row, int col){
        if(node==nullptr){
            return;
        }
        store[col].push_back({row,node->val});
        traverse(node->left,store,row+1,col-1);
        traverse(node->right,store,row+1,col+1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> store;
        traverse(root,store,0,0);

        vector<vector<int>>ans;

        for(auto ele:store){
            stable_sort(ele.second.begin(),ele.second.end());

            vector<int>temp;

            for(auto e:ele.second){
                temp.push_back(e.second);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
