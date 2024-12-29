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

    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;

        while(temp){
            ListNode* next = temp->next;
            temp->next=prev;
            prev = temp;
            temp=next;
        }

        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1Prev = l1;
        ListNode* l2Prev = l2;

        ListNode* result=NULL;
        ListNode* head;
        ListNode*temp = NULL;
        int carry=0;

        while(l1Prev || l2Prev || carry){
            int tot = 0;
            if(l1Prev) tot+=l1Prev->val,l1Prev = l1Prev->next;
            if(l2Prev) tot+=l2Prev->val,l2Prev = l2Prev->next;

            int rem = (tot+carry+10)%10;
            carry = (tot+carry)/10;

            temp = new ListNode(rem);

            if(!result) result = temp,head=result;
            else{
                result->next=temp;
                result=result->next;
            }

        }

        return head;

    }
};
