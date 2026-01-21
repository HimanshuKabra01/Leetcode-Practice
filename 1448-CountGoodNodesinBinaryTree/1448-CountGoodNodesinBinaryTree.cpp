// Last updated: 1/21/2026, 11:20:43 AM
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
14    void rec(TreeNode* root, int& ans, int max) {
15        if(root == NULL) {
16            return;
17        }
18
19        if(root->val >= max) {
20            ans++;
21            max = root->val;
22        }
23        rec(root->left, ans, max);
24        rec(root->right, ans, max);
25    }
26    int goodNodes(TreeNode* root) {
27        int ans = 0;
28
29        int max = root->val;
30
31        rec(root, ans, max);
32
33        return ans;
34    }
35};