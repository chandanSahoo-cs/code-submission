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
    vector<ListNode*> reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* tail = temp;
        while(temp){
            ListNode* next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }

        return {prev,head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int cnt=0;
        ListNode* ans = NULL;
        ListNode* temp = head;
        ListNode* strt = head;
        ListNode* prev = NULL;


        while(temp){
            ListNode* next = temp->next;

            if(cnt==0){
                strt = temp;
            }
            cnt++;

            if(cnt==k){
                temp->next = NULL;

                if(ans==NULL){
                    ans = temp;
                }

                vector<ListNode*>con = reverseLL(strt);

                con[1]->next = next;
                // cout<<con->val<<" ";
                // con->next = next;

                if(prev==NULL) prev = con[1];
                else{
                    prev->next = con[0];
                    prev = con[1];
                }
                // temp->next = next;
                cnt=0;
            }
            temp = next;
        }

        return ans; 
    }

};
