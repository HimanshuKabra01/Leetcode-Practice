// Last updated: 1/4/2026, 7:22:45 PM
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
13    ListNode* swapNodes(ListNode* head, int k) {
14        int count = 0;
15        ListNode* curr = head;
16
17        while(curr != NULL) {
18            count++;
19
20            curr = curr->next;
21        }
22
23        curr = head;
24        int elemCount = 0;
25
26        int val1 = 0;
27        int val2 = 0;
28
29        while(curr != NULL) {
30            elemCount++;
31
32            if(elemCount == k) {
33                val1 = curr->val;
34            }
35
36            if(elemCount == count - k + 1) {
37                val2 = curr->val;
38            }
39
40            curr = curr->next;
41        }
42
43        curr = head;
44        elemCount = 0;
45
46        while(curr != NULL) {
47            elemCount ++;
48
49            if(elemCount == k) {
50                curr->val = val2;
51            }
52
53            if(elemCount == count - k + 1) {
54                curr->val = val1;
55            }
56
57            curr = curr->next;
58        }   
59
60        return head;
61    }
62};