/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    /*
    - level order traversal
    - from one node to its adjacent node I can go through next
    */
    Node* connect(Node* root) {
        Node* curr = root;

        while(curr){
            Node* next = curr->left;
            Node* temp = nullptr;

            while(curr){
                if(temp==nullptr){
                    temp = curr->left;
                }else{
                    temp->next = curr->left;
                    temp = temp->next;
                }

                if(temp==nullptr){
                    temp = curr->right;
                }else{
                    temp->next = curr->right;
                    temp = temp->next;
                }

                curr = curr->next;
            }

            curr = next;
        }

        return root;
    }
};
