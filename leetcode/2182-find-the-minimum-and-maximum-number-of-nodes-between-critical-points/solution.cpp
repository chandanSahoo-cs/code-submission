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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head->next==nullptr) return {-1,-1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        int frst = -1;

        int i = 1, prevC = -1;

        int mn = INT_MAX;

        auto check = [&](ListNode* prev, ListNode* curr, ListNode* next)->bool{
            int prevVal = prev->val;
            int currVal = curr->val;
            int nextVal = next->val;

            if(prevVal>currVal && currVal<nextVal) return true;
            if(prevVal<currVal && currVal>nextVal) return true;

            return false;
        };

        while(curr->next!=nullptr){
            ListNode* next = curr->next;
            if(check(prev,curr,next)){
                if(prevC!=-1){
                    mn = min(mn,i-prevC);
                }
                if(frst==-1){
                    frst = i;
                }
                prevC = i;
            }
            prev = curr;
            curr = next;
            i++;
        }

        if(mn==INT_MAX) return {-1,-1};
        return {mn,prevC-frst};
    }
};
