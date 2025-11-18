// Last updated: 11/18/2025, 3:32:24 PM
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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            if(curr->val == val) {
                if(prev == NULL){
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }

                curr = curr->next;
                continue;
            }

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};