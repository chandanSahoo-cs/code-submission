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
    Node* connect(Node* root) {
        Node* curr = root;

        while(curr){
            Node* next = nullptr;

            Node* temp = nullptr;

            while(curr){
                if(curr->left){
                    if(temp==nullptr){
                        temp = curr->left;
                    }else{
                        temp->next = curr->left;
                        temp = temp->next;
                    }

                    if(!next) next = curr->left;
                }
                
                if(curr->right){
                    if(temp==nullptr){
                        temp = curr->right;
                    }else{
                        temp->next = curr->right;
                        temp = temp->next;
                    }

                    if(!next) next = curr->right;
                }

                curr = curr->next;
            }

            curr = next;
        }

        return root;
    }
};
