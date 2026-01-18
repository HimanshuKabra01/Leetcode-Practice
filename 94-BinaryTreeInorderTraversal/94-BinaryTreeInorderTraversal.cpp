// Last updated: 1/18/2026, 4:18:15 PM
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
14    void inorder(TreeNode* root, vector<int>& ans) {
15        if(root == NULL) {
16            return;
17        }
18
19        inorder(root->left, ans);
20        ans.push_back(root->val);
21        inorder(root->right, ans);
22    }
23
24    vector<int> inorderTraversal(TreeNode* root) {
25        vector<int> ans;
26
27        inorder(root, ans);
28
29        return ans;
30    }
31};