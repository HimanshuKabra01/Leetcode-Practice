// Last updated: 11/5/2025, 5:29:54 PM
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
    ListNode* deleteDuplicates(ListNode* head) {
        unordered_set<int> s;

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL){
            if(s.find(curr->val) != s.end()) {
                if(prev == NULL){
                    head = curr->next;
                } else {
                    prev->next = curr->next;
                }

                curr = curr->next;
                continue;
            } else {
                s.insert(curr->val);
            }

            prev = curr;
            curr = curr->next;
        }

        return head;
    }
};