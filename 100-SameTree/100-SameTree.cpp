// Last updated: 1/21/2026, 6:11:32 PM
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
14    TreeNode* inverse(TreeNode* root) {
15        if(root == NULL) {
16            return NULL;
17        }
18
19        TreeNode* temp = root->left;
20        root->left = root->right;
21        root->right = temp;
22
23        inverse(root->left);
24        inverse(root->right);
25
26        return root;
27    }
28
29    bool isSameTree(TreeNode* p, TreeNode* q) {
30        if(p == NULL && q == NULL) {
31            return true;
32        }
33
34        if(p == NULL ||  q == NULL) {
35            return false;
36        }
37
38        if(p->val != q->val) {
39            return false;
40        }
41
42        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
43    }
44
45    bool isSymmetric(TreeNode* root) {
46        TreeNode* ri = inverse(root->right);
47
48        return isSameTree(root->left, ri);
49    }
50};