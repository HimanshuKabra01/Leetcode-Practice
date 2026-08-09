// Last updated: 8/9/2026, 12:34:15 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int ans = INT_MIN;
        int lvlAns = 0;
        int lvl = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        int currAns = 0;
        while(!q.empty()) {
            TreeNode* curr = q.front();

            q.pop();
            if(curr == NULL) {
                lvl++;
                if(currAns > ans) {
                    ans = currAns;
                    lvlAns = lvl;
                }

                currAns = 0;
                if(!q.empty()) {
                    q.push(NULL);
                    continue;
                } else {
                    break;
                }
            } else {
                currAns += curr->val;
            }

            if(curr->left != NULL) {
                q.push(curr->left);
            }
            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }

        return lvlAns;
    }
};