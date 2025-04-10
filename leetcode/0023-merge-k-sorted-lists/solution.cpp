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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto ele:lists){
            ListNode*temp = ele;
            while(temp!=nullptr){
                pq.push(temp->val);
                temp=temp->next;
            }
        }

        ListNode*head=nullptr;
        ListNode*curr=nullptr;

        while(!pq.empty()){
            ListNode* temp = new ListNode(pq.top());
            if(head==nullptr){
                head=temp;
                curr=temp;
            }else{
                curr->next=temp;
                curr=curr->next;
            }
            pq.pop();
        }

        return head;
    }
};
