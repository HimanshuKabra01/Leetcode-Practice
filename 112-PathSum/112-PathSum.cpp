// Last updated: 8/9/2026, 12:41:01 PM
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
    unordered_set<int> s;
    void rec(TreeNode* root, int &ans) {
        if(root == NULL){
            return;
        }

        ans += root->val;

        if(root->left == NULL && root->right == NULL) {
            s.insert(ans);
        }

        rec(root->left, ans);
        rec(root->right, ans);

        ans -= root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int ans = 0;

        rec(root, ans);

        if(s.find(targetSum) == s.end()) {
            return false;
        } else {
            return true;
        }
    }
};