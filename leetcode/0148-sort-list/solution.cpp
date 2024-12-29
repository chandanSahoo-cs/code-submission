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

    ListNode* giveMiddle(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;


        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode*middle = slow->next;
        slow->next=NULL;
        return middle;
    }

    ListNode* merge(ListNode* arr1, ListNode* arr2){
        // if(arr1->val>arr2->val) swap(arr1,arr2);
        ListNode* prev = NULL;
        ListNode * arr1P = arr1;
        ListNode * arr2P = arr2;
        

        while(arr1P && arr2P){
            if(arr1P->val<=arr2P->val){
                if(arr1P->next==NULL) break;
                prev = arr1P;
                arr1P=arr1P->next;
            }
            else{
                ListNode*next = arr2P->next;
                if(prev==NULL){
                    arr2P->next=arr1P;
                    prev = arr2P;    
                    arr1 = arr2P;
                }
                else{
                    prev->next=arr2P;
                    arr2P->next=arr1P;
                    prev = arr2P;
                }
                arr2P=next;
            }
        }

        while(arr2P){
            arr1P->next=arr2P;
            arr1P=arr1P->next;
            arr2P=arr2P->next;
        }
        return arr1;
    }

    ListNode* mergeSort(ListNode* arr) {
        if (arr==NULL || arr->next == NULL) return arr;
        ListNode* right = giveMiddle(arr);
        ListNode* arr1 = mergeSort(arr);
        ListNode* arr2 = mergeSort(right);
        ListNode* keep = arr2;

        return merge(arr1, arr2);
    }

    ListNode* sortList(ListNode* head) {
       return mergeSort(head); 
    }
};
