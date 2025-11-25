// Last updated: 11/25/2025, 3:08:25 PM
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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return NULL;

        ListNode* temp = head;
        int k = 2;
        int cnt = 0;

        while(cnt < k) {
            if(temp == NULL) {
                return head;
            }

            temp = temp->next;
            cnt++;
        }

        ListNode* prevNode = swapPairs(temp);

        temp = head;
        cnt = 0;

        while(cnt < k) {
            ListNode* next = temp->next;

            temp->next = prevNode;

            prevNode = temp;
            temp = next;

            cnt++;
        }

        return prevNode;
    }
};