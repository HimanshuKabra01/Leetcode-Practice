// Last updated: 8/9/2026, 12:36:30 PM
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
    bool isPossible = false;
    unordered_set<int> s;
    void helper(TreeNode* root, int k) {
        if(root == NULL) {
            return;
        }

        helper(root->left, k);

        int needed = k - root->val;

        if(s.count(needed)) {
            isPossible = true;
        } else {
            s.insert(root->val);
        }

        helper(root->right, k);
        return;
    }
    bool findTarget(TreeNode* root, int k) {

        helper(root, k);

        return isPossible; 
    }
};