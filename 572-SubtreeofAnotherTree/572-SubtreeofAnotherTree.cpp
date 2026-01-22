// Last updated: 1/22/2026, 10:58:15 PM
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
14    bool isSame(TreeNode* p, TreeNode* q) {
15        if(p == NULL && q == NULL) {
16            return true;
17        }
18
19        if(p == NULL || q == NULL) {
20            return false;
21        }
22
23        if(p->val != q->val) {
24            return false;
25        }
26
27        return isSame(p->left, q->left) && isSame(p->right, q->right);
28    }
29
30    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
31        if(root == NULL || subRoot == NULL) {
32            return false;
33        }
34
35        if(root->val == subRoot->val) {
36            if(isSame(root, subRoot)) {
37                return true;
38            }
39        }
40
41        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
42    }
43};