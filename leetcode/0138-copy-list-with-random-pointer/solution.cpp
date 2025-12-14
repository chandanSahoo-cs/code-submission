/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;

        while(curr){
            Node* temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        curr = head;

        while(curr){
            Node* next = curr->next->next;
            
            Node* cCurr = curr->next;
            Node* cRan = curr->random?curr->random->next:nullptr;
            
            cCurr->random = cRan;
            curr = next;
        }

        curr = head;
        Node* root = nullptr;

        while(curr){
            if(curr==head) root = curr->next;
            
            Node* next = curr->next->next;

            Node* cCurr = curr->next;
            Node* cNext = next?next->next:nullptr;

            cCurr->next = cNext;

            curr->next = next;
            curr = next;
        }

        return root;
    }
};
