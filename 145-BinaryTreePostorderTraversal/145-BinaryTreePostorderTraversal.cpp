// Last updated: 1/19/2026, 1:03:24 AM
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
14    void post(TreeNode* root, vector<int>& ans) {
15        if(root == NULL) {
16            return;
17        }
18
19        post(root->left, ans);
20        post(root->right, ans);
21        ans.push_back(root->val);
22    }
23    vector<int> postorderTraversal(TreeNode* root) {
24        vector<int> ans;
25
26        post(root, ans);
27
28        return ans;
29    }
30};