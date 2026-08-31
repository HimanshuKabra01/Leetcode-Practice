// Last updated: 9/1/2026, 1:07:21 AM
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
13    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
14        vector<int> ans;
15
16        int prev = head->val;
17        ListNode* curr = head->next;
18        int dist = 1;
19
20        while(curr->next != NULL) {
21            int c = curr->val;
22
23            if((c > prev && c > curr->next->val) || (c < prev && c < curr->next->val)) {
24                ans.push_back(dist);
25            }
26
27            dist++;
28            curr = curr->next;
29            prev = c;
30        }
31
32
33        if(ans.size() < 2) {
34            return {-1,-1};
35        }
36
37        int mn = INT_MAX;
38        for (int i = 1; i < ans.size(); i++) {
39            mn = min(mn, ans[i] - ans[i-1]);
40        }
41
42        return {mn, ans[ans.size()-1]-ans[0]};
43    }
44};