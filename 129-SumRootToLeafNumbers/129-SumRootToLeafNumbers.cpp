// Last updated: 8/9/2026, 12:40:22 PM
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
    void rec(TreeNode* root, int &ans, string &curr) {
        if(root == NULL){
            return;
        }

        curr += to_string(root->val);

        if(root->left == NULL && root->right == NULL) {
            ans += stoi(curr);
        }

        rec(root->left, ans, curr);
        rec(root->right, ans, curr);

        curr.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        string curr = "";

        rec(root, ans, curr);

        return ans;
    }
};