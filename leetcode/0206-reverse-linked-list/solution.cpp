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

    ListNode* recursive(ListNode* curr,ListNode*prev){
        if(curr==NULL) return prev;
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        
        return recursive(next,prev);
    }

    ListNode* reverseList(ListNode* head) {
        // ListNode* temp = head;
        // ListNode* keep = NULL;
        // if(head==NULL) return head;
        // while(temp->next){
        //     ListNode* next = temp->next;
        //     temp->next = keep;
        //     keep = temp;
        //     temp = next;
        // }

        // temp->next = keep;
        // head = temp;

        return recursive(head,NULL);
    }
};
