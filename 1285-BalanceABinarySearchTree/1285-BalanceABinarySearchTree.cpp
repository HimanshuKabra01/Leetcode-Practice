// Last updated: 8/9/2026, 12:33:56 PM
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
    void trav(TreeNode* root, vector<int> &inorder) {
        if(root == NULL) {
            return;
        }

        trav(root->left, inorder);
        inorder.push_back(root->val);
        trav(root->right, inorder);
    }

    TreeNode* buildTree(TreeNode* &root, vector<int> &inorder, int st, int end) {
        if(st > end) {
            return NULL;
        }

        int mid = st + (end-st)/2;

        if(root == NULL) {
            root = new TreeNode(inorder[mid]);
        }

        root->left = buildTree(root->left, inorder, st, mid - 1);
        root->right = buildTree(root->right, inorder, mid + 1, end);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> inorder;
        trav(root, inorder);

        TreeNode* ans = NULL;

        TreeNode* ret = buildTree(ans, inorder, 0, inorder.size()-1);

        return ret;
    }
};