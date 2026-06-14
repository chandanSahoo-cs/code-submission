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
    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(slow->next && fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* half = slow->next;
        ListNode* prev = nullptr;

        while(half){
            ListNode* next = half->next;
            half->next = prev;
            prev = half;
            half = next;
        }

        int mx = 0;

        while(prev && head){
            mx = max(prev->val+head->val,mx);
            prev = prev->next;
            head = head->next;
        }

        return mx;
    }
};
