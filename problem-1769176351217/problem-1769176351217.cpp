// Last updated: 1/23/2026, 7:22:31 PM
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
22        return 1 + max(l,r);
23    }
24
25    int diameterOfBinaryTree(TreeNode* root) {
26        if(root == NULL) {
27            return 0;
28        }
29
30        int leftD = diameterOfBinaryTree(root->left);
31        int rightD = diameterOfBinaryTree(root->right);
32        int currD = height(root->left) + height(root->right);
33
34        int maxi = max(leftD, rightD);
35
36        return max(currD, maxi);
37    }
38};