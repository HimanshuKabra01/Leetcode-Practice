// Last updated: 11/2/2025, 3:43:41 PM
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        
        int count = 0;
        while(curr != NULL) {
            count++;

            curr = curr->next;
        }

        if(count == 1) {
            return NULL;
        }

        curr = head;
        int mid = count / 2;
        int elemCount = 0;

        while(curr != NULL){
            elemCount++;

            if(elemCount == mid + 1) {
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