// Last updated: 8/9/2026, 12:33:19 PM
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
    void rec(TreeNode* root, int& ans, int max) {
        if(root == NULL) {
            return;
        }

        if(root->val >= max) {
            ans++;
            max = root->val;
        }
        rec(root->left, ans, max);
        rec(root->right, ans, max);
    }
    int goodNodes(TreeNode* root) {
        int ans = 0;

        int max = root->val;

        rec(root, ans, max);

        return ans;
    }
};