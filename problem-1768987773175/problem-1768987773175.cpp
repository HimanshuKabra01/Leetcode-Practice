// Last updated: 1/21/2026, 2:59:33 PM
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
14    TreeNode* inv(TreeNode* root) {
15        if(root == NULL) {
16            return NULL;
17        }
18
19        TreeNode* temp = root->left;
20        root->left = root->right;
21        root->right = temp;
22
23        inv(root->left);
24        inv(root->right);
25
26        return root;
27    }
28    TreeNode* invertTree(TreeNode* root) {
29        TreeNode* ans = inv(root);
30
31        return ans;
32    }
33};