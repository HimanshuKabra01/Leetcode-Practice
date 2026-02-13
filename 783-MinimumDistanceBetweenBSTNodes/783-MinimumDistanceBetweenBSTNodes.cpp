// Last updated: 2/13/2026, 10:50:13 PM
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
14    int ans = INT_MAX;
15
16    void inorder(TreeNode* root, TreeNode* &prev) {
17        if(root == NULL) {
18            return;
19        }
20
21        inorder(root->left, prev);
22
23        if(prev != NULL) {
24            ans = min(ans, abs(root->val - prev->val));
25        }
26
27        prev = root;
28
29        inorder(root->right, prev);
30    }
31    int minDiffInBST(TreeNode* root) {
32        TreeNode* prev = NULL;
33
34        inorder(root, prev);
35
36        return ans;
37    }
38};