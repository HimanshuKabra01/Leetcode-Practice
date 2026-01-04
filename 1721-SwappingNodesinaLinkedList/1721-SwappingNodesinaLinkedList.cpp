// Last updated: 1/4/2026, 7:23:22 PM
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int n = 0;
        ListNode* cur = head;
        while (cur) {
            n++;
            cur = cur->next;
        }
        ListNode* first = head;
        ListNode* second = head;
        for (int i = 1; i < k; i++)
            first = first->next;
        for (int i = 1; i < n - k + 1; i++)
            second = second->next;

        swap(first->val, second->val);
        return head;
    }
};
