// Last updated: 2/18/2026, 1:26:35 AM
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
14    TreeNode* first = NULL;
15    TreeNode* second = NULL;
16    TreeNode* prev = NULL;
17
18    void trav(TreeNode* root) {
19        if(root == NULL) {
20            return;
21        }
22
23        trav(root->left);
24        
25        if(prev && prev->val > root->val) {
26            if(!first) {
27                first = prev;
28            }
29
30            second = root;
31        }
32
33        prev = root;
34
35        trav(root->right);        
36    }
37
38    void recoverTree(TreeNode* root) {
39        trav(root);
40
41        swap(first->val, second->val);
42    }
43};