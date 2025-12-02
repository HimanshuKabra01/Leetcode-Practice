// Last updated: 12/2/2025, 5:54:08 PM
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
13    bool isPalindrome(ListNode* head) {
14
15        ListNode* curr = head;
16        int cnt = 0;
17
18        while(curr != NULL) {
19            cnt++;
20            curr = curr->next;
21        }
22
23        if(cnt <= 1) return true;
24
25        stack<int> st;
26        curr = head;
27        int half = cnt/2;
28        int idx = 0;
29
30        while(idx < half){
31            st.push(curr->val);
32            idx++;
33            curr = curr->next;
34        }
35
36        if(cnt % 2 != 0){
37            curr = curr->next;
38        }
39
40        while(curr != NULL){
41            if(st.top() != curr->val) {
42                return false;
43            }
44            st.pop();
45            curr = curr->next;
46        }
47
48        return true;
49    }
50};