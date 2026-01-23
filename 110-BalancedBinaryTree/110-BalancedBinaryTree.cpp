// Last updated: 1/24/2026, 1:33:41 AM
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
14    int height(TreeNode* root) {
15        if(root == NULL) {
16            return 0;
17        }
18
19        int l = height(root->left);
20        int r = height(root->right);
21
22        return 1 + max(l, r);
23    }
24    bool isBalanced(TreeNode* root) {
25        if(root == NULL) {
26            return true;
27        }
28
29        int l = height(root->left);
30        int r = height(root->right);
31
32        if(abs(l-r) > 1) {
33           return false; 
34        }
35
36        return isBalanced(root->left) && isBalanced(root->right);
37    }
38};