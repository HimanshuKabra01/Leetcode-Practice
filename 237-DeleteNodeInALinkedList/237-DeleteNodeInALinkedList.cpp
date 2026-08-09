// Last updated: 8/9/2026, 12:38:18 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* next = node->next;

        node->val = node->next->val;
        node->next = node->next->next;

        delete next;
    }
};