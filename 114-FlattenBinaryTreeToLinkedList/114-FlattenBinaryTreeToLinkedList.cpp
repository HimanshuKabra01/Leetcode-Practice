// Last updated: 8/9/2026, 12:40:51 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;  vf
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(TreeNode* root) {
        if(root == NULL) {
            return NULL;
        }

        TreeNode* leftTail = helper(root->left);
        TreeNode* rightTail = helper(root->right);

        if(root->left != NULL) {
            TreeNode* temp = root->right;
            root->right = root->left;
            leftTail->right = temp;
            root->left = NULL;
        }

        if(rightTail) {
            return rightTail;
        } else if(leftTail) {
            return leftTail;
        } else {
            return root;
        }
    }
    void flatten(TreeNode* root) {
        helper(root);
    }
};