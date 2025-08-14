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
    void addString(string &s,int val){
        string numS = to_string(val);
        if(s!=""){
            s+='-';
            s+='>';
        }

        for(auto ele:numS){
            s.push_back(ele);
        }
    }

    void removeString(string &s, int val){
        string numS = to_string(val);
        while(!numS.empty()){
            if(numS.back()==s.back()){
                numS.pop_back();
                s.pop_back();
            }
        }

        if(s!=""){
            s.pop_back();
            s.pop_back();
        }
    }


    void traverse(TreeNode* node, string &s, vector<string>&ans){
        if(node->left==nullptr && node->right==nullptr){
            addString(s,node->val);
            ans.push_back(s);
            removeString(s,node->val);
            return;
        }

        addString(s,node->val);

        if(node->left!=nullptr) traverse(node->left,s,ans);
        if(node->right!=nullptr) traverse(node->right,s,ans);

        removeString(s,node->val);

    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        string s = "";
        vector<string>ans;
        traverse(root,s,ans);
        return ans;
    }
};
