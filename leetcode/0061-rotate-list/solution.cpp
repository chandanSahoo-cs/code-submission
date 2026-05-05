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
        int len = 0;

        if(!head) return head;
        
        ListNode* last = head;

        while(last->next){
            last = last->next;
            len++;
        }
        len++;

        if(k%len==0) return head;
        k = k%len;

        int rotpt = len-k-1;

        ListNode* temp = head;

        while(rotpt--){
            temp = temp->next;
        }

        ListNode* nhead = temp->next;
        last->next = head;
        temp->next = nullptr;

        return nhead;

    }
};
