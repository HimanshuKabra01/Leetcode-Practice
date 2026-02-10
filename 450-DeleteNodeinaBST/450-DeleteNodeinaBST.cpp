// Last updated: 2/10/2026, 1:00:22 PM
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
14    TreeNode* getIS(TreeNode* root) {
15        while(root != NULL && root->left != NULL) {
16            root = root->left;
17        }
18
19        return root;
20    }
21
22    TreeNode* deleteNode(TreeNode* root, int key) {
23        if(root == NULL) {
24            return NULL;
25        }
26
27        if(key < root->val) {
28            root->left = deleteNode(root->left, key);
29        } else if(key > root->val) {
30            root->right = deleteNode(root->right, key);
31        } else {
32            if(root->left == NULL) {
33                TreeNode* temp = root->right;
34                delete root;
35                return temp;
36            } else if(root->right == NULL) {
37                TreeNode* temp = root->left;
38                delete root;
39                return temp;
40            } else {
41                TreeNode* IS = getIS(root->right);
42                root->val = IS->val;
43
44                root->right = deleteNode(root->right, IS->val);
45            }
46        }
47
48        return root;
49    }
50};