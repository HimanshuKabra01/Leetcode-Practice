// Last updated: 8/9/2026, 12:38:22 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        
        if(root == p || root == q) {
            return root;
        }

        TreeNode* leftLCA = rec(root->left, p, q);
        TreeNode* rightLCA = rec(root->right, p, q);

        if(leftLCA && rightLCA) {
            return root;
        } else if(leftLCA) {
            return leftLCA;
        } else {
            return rightLCA;
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = rec(root, p, q);

        return ans;
    }
};