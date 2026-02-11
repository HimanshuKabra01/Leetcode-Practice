// Last updated: 2/11/2026, 12:51:43 PM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10
11class Solution {
12public:
13    TreeNode* rec(TreeNode* root, TreeNode* p, TreeNode* q) {
14        if(root == NULL) {
15            return NULL;
16        }
17        
18        if(root == p || root == q) {
19            return root;
20        }
21
22        TreeNode* leftLCA = rec(root->left, p, q);
23        TreeNode* rightLCA = rec(root->right, p, q);
24
25        if(leftLCA && rightLCA) {
26            return root;
27        } else if(leftLCA) {
28            return leftLCA;
29        } else {
30            return rightLCA;
31        }
32    }
33    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
34        TreeNode* ans = rec(root, p, q);
35
36        return ans;
37    }
38};