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

#define ll long long
class Solution {
public:
    void traverse(queue<pair<ll,TreeNode*>> &q, ll &mx){
        if(q.front().second==nullptr) return;

        while(!q.empty()){
            vector<pair<ll,TreeNode*>>track;

            while(!q.empty()){
                track.push_back(q.front());
                q.pop();
            }

            ll l=-1,r;

            ll base = track[0].first;

            for(auto ele:track){
                if(l==-1){
                    l=ele.first;
                    r=l;
                }else{
                    r=ele.first;
                }
                if(ele.second->left!=nullptr) q.push({2*(ele.first-base),ele.second->left});
                if(ele.second->right!=nullptr) q.push({2*(ele.first-base)+1,ele.second->right});
            }

            mx = max(mx,r-l+1);
        }
    }

    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<ll,TreeNode*>>q;
        q.push({0,root});
        ll mx=0;
        traverse(q,mx);

        return mx;
    }
};
