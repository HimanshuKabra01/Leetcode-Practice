// Last updated: 1/5/2026, 11:32:23 PM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
14        ListNode* dummy = new ListNode(0);
15        int carry = 0;
16        ListNode* curr = dummy;
17
18        while(l1 != NULL || l2 != NULL || carry != 0) {
19            int val1 = (l1 != NULL) ? l1 -> val : 0;
20            int val2 = (l2 != NULL) ? l2 -> val : 0;
21
22            int sum = val1 + val2 + carry;
23            carry = sum / 10;
24
25            curr->next = new ListNode(sum % 10);
26
27            curr = curr->next;
28            if(l1 != NULL) l1 = l1->next;
29            if(l2 != NULL) l2 = l2->next;
30        }
31
32        ListNode* result = dummy -> next;
33        delete dummy;
34        return result;
35    }
36};