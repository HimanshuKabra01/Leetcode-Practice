// Last updated: 8/9/2026, 12:35:42 PM
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
    int ans = INT_MAX;

    void inorder(TreeNode* root, TreeNode* &prev) {
        if(root == NULL) {
            return;
        }

        inorder(root->left, prev);

        if(prev != NULL) {
            ans = min(ans, abs(root->val - prev->val));
        }

        prev = root;

        inorder(root->right, prev);
    }
    int minDiffInBST(TreeNode* root) {
        TreeNode* prev = NULL;

        inorder(root, prev);

        return ans;
    }
};