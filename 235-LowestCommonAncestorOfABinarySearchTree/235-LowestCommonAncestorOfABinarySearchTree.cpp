// Last updated: 8/9/2026, 12:38:26 PM
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

        if(p->val < root->val && q->val < root->val) {
            return rec(root->left, p, q);
        } else if(p->val > root->val && q->val > root->val) {
            return rec(root->right, p, q);
        }

        return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = rec(root, p, q);

        return ans;
    }
};