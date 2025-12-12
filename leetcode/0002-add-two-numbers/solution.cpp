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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        ListNode* dummy = new ListNode();
        ListNode* tail = dummy;

        while(curr1 || curr2 || carry){
            int val = 0;
            if(curr1){
                val+=curr1->val;
                curr1=curr1->next;
            }

            if(curr2){
                val+=curr2->val;
                curr2=curr2->next;
            }

            if(carry){
                val+=carry;
            }
            carry=val/10;
            tail->next = new ListNode(val%10);
            tail=tail->next;
        }

        return dummy->next;
    }
};
