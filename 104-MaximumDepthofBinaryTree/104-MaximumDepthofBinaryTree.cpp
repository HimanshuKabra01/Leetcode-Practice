// Last updated: 1/20/2026, 6:46:08 PM
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
14    int rec(TreeNode* root) {
15        if(root == NULL) {
16            return 0;
17        }
18
19        int left = rec(root->left);
20        int right = rec(root->right);
21
22        return 1 + max(left, right);
23    }
24    int maxDepth(TreeNode* root) {
25        int ans = rec(root);
26
27        return ans;
28    }
29};