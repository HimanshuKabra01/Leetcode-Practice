// Last updated: 2/1/2026, 12:11:49 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Solution {
11public:
12    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q) {
13        if(root == NULL) {
14            return NULL;
15        }
16        
17        if(root == p || root == q) {
18            return root;
19        }
20
21        TreeNode* leftLCA = rec(root->left, p, q);
22        TreeNode* rightLCA = rec(root->right, p, q);
23
24        if(leftLCA && rightLCA) {
25            return root;
26        } else if(leftLCA) {
27            return leftLCA;
28        } else {
29            return rightLCA;
30        }
31    }
32    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
33        TreeNode* ans = rec(root, p, q);
34
35        return ans;
36    }
37};