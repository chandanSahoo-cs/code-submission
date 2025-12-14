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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;

        ListNode* curr = head;

        int len = 1;
        while(curr && curr->next){
            curr=curr->next;
            len++;
        }

        k = k%len;
        if(k==0) return head;
        
        curr->next = head;


        int cut = len-k-1;

        ListNode* temp = head;
        while(cut--){
            temp=temp->next;
        }

        ListNode* next = temp->next;
        temp->next = nullptr;

        return next;
    }
};
