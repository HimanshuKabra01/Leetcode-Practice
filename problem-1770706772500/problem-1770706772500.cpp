// Last updated: 2/10/2026, 12:29:32 PM
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
14    TreeNode* insert(TreeNode* root, int val) {
15        if(root == NULL) {
16            return new TreeNode(val);
17        }
18
19        if(val < root->val) {
20            root->left = insert(root->left, val);
21        } else {
22            root->right = insert(root->right, val);
23        }
24
25        return root;
26    }
27    TreeNode* bstFromPreorder(vector<int>& preorder) {
28        TreeNode* root = NULL;
29
30        for(int i = 0; i < preorder.size(); i++) {
31            root = insert(root, preorder[i]);
32        }
33
34        return root;
35    }
36};