// Last updated: 1/8/2026, 1:25:03 AM
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
13    void reorderList(ListNode* head) {
14
15        if(head == NULL || head->next == NULL || head->next->next == NULL) return;
16      ListNode* curr = head;
17      ListNode* next = head->next;
18
19      while(curr->next->next != NULL){
20
21        curr = curr->next;
22      }
23
24
25      head->next = curr->next;
26      curr->next->next = next;
27
28      curr->next = NULL; 
29
30      reorderList(next);
31    }
32};