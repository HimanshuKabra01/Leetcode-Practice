// Last updated: 2/13/2026, 1:08:32 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    bool helper(TreeNode* root, long long left, long long right) {
15        if(root == NULL) {
16            return true;
17        }
18
19        if(left >= root->val || right <= root->val) {
20            return false;
21        }
22
23        return helper(root->left, left, root->val) && helper(root->right, root->val, right);
24    }
25    bool isValidBST(TreeNode* root) {
26        return helper(root, LLONG_MIN, LLONG_MAX);
27    }
28};