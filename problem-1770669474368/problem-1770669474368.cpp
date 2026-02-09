// Last updated: 2/10/2026, 2:07:54 AM
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
14    void search(TreeNode* root, TreeNode* &ans, int val) {
15        if(root == NULL) {
16            return;
17        }
18
19        if(val == root->val) {
20            ans = root;
21        } else if(val < root->val) {
22            search(root->left, ans, val);
23        } else {
24            search(root->right, ans, val);
25        }
26    }
27    TreeNode* searchBST(TreeNode* root, int val) {
28        TreeNode* ans = NULL;
29
30        search(root, ans, val);
31
32        return ans;
33    }
34};