// Last updated: 8/9/2026, 12:41:19 PM
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
    int rec(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }

        int left = rec(root->left);
        int right = rec(root->right);

        return 1 + max(left, right);
    }
    int maxDepth(TreeNode* root) {
        int ans = rec(root);

        return ans;
    }
};