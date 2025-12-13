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
    void reverseLL(ListNode* head, int k){
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(k){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }
    }


    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* curr = head;
        ListNode* root = head;

        ListNode* strt = head;
        ListNode* prev = nullptr;

        bool flag=true;
        int cnt=0;

        while(curr){
            ListNode* next = curr->next;
            cnt++;

            if(cnt==k){
                cnt=0;
                reverseLL(strt,k);
                if(prev){
                    prev->next = curr;
                }

                prev = strt;
                strt = next;

                if(flag){
                    root = curr;
                    flag=false;
                }

            }

            curr=next;
        }

        prev->next = strt;

        return root;    
    }
};
