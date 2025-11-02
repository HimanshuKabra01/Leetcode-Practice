// Last updated: 11/2/2025, 3:25:54 PM
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        ListNode* prev = NULL;

        int count = 0;

        while(curr != NULL) {
            count++;

            curr = curr->next;
        }

        int pos = count - n + 1;
        int posCount = 0;
        curr = head;

        if(count == 1) {
            return NULL;
        }

        while(curr != NULL) {
            posCount++;

            if(posCount == pos) {
                if(prev == NULL) {
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