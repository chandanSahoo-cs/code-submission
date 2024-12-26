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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(n>1){
            temp2=temp2->next;
            n--;
        }
        ListNode* temp3=NULL;
        while(temp2 && temp2->next){
            temp2=temp2->next;
            temp3=temp1;
            temp1=temp1->next;
        }
        cout<<temp1->val<<"\n";
        if(temp1->next) temp1->val=temp1->next->val;
        if(temp1->next) temp1->next=temp1->next->next;
        else{
            if(!temp3) return temp3;
            temp3->next=NULL;
            
        }
        return head;

    }
};
