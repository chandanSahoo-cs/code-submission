/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    vector<ListNode*>reverseLL(ListNode* head){
        if(head->next==NULL) return {head,head};
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return{prev,head};
    }

    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        if(head==NULL || head->next==NULL || k==0) return head;
        int len = 0;

        while(temp){
            len++;
            temp=temp->next;
        }

        k = len - k%len ;
        if(k==len) return head;

        int c = 0;
        temp = head;
        while(temp){
            c++;
            if(c==k){
                ListNode*next = temp->next;
                temp->next = NULL;
                vector<ListNode*>v1 = reverseLL(head);
                vector<ListNode*>v2 = reverseLL(next);
                head=v1[0];
                v1[1]->next = v2[0];
            }
            temp=temp->next;
        }

        vector<ListNode*>v = reverseLL(head);

        return v[0] ;
    }
};
