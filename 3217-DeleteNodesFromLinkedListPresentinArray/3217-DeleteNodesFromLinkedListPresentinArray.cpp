// Last updated: 11/2/2025, 12:12:22 AM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        unordered_set<int> s;

        for(int i = 0; i < n; i++) {
            if(s.find(nums[i]) == s.end()) {
                s.insert(nums[i]);
            }
        }

        ListNode* curr = head;
        ListNode* prev = NULL;

        while(curr != NULL) {

            if(s.find(curr->val) != s.end()) {
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