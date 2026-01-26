/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node==nullptr) return nullptr;
        queue<pair<Node*,Node*>>q;
        unordered_map<Node*,Node*>mp;
        
        Node* root = new Node(node->val);
        mp[node] = root;
        q.push({node,root});

        while(!q.empty()){
            auto [curr,copy] = q.front();
            q.pop();

            for(auto ele:curr->neighbors){
                if(mp.find(ele)!=mp.end()){
                    copy->neighbors.push_back(mp[ele]);
                }else{
                    Node* temp = new Node(ele->val);
                    mp[ele] = temp;
                    q.push({ele,temp});
                    copy->neighbors.push_back(mp[ele]); 
                }
            }
        }

        return root;

    }
};
