// Last updated: 2/7/2026, 11:13:49 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;  vf
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    TreeNode* helper(TreeNode* root) {
15        if(root == NULL) {
16            return NULL;
17        }
18
19        TreeNode* leftTail = helper(root->left);
20        TreeNode* rightTail = helper(root->right);
21
22        if(root->left != NULL) {
23            TreeNode* temp = root->right;
24            root->right = root->left;
25            leftTail->right = temp;
26            root->left = NULL;
27        }
28
29        if(rightTail) {
30            return rightTail;
31        } else if(leftTail) {
32            return leftTail;
33        } else {
34            return root;
35        }
36    }
37    void flatten(TreeNode* root) {
38        helper(root);
39    }
40};