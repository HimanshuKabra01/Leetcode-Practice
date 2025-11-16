// Last updated: 11/16/2025, 11:41:09 AM
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempOne = headA;
        ListNode* tempTwo = headB;

        while(tempOne != NULL){
            while(tempTwo != NULL) {
                if(tempOne== tempTwo) {
                    return tempOne;
                }

                tempTwo = tempTwo->next;
            }

            tempOne = tempOne->next;
            tempTwo = headB;
        }

        return NULL;
    }
};