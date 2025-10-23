// Last updated: 10/23/2025, 2:41:48 PM
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
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        int elemCount = 0;
        ListNode* temp = head;
        ListNode* curr = head;

        while(temp != NULL) {
            count++;
            temp = temp->next;
        }

        int mid = count / 2;

        while(curr != NULL) {
            elemCount++;

            if(elemCount == mid + 1) {
                return curr;
            }

            curr = curr->next;
        }

        return NULL;
    }
};