// Last updated: 2/21/2026, 1:03:39 PM
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
14    void trav(TreeNode* root, vector<int> &inorder) {
15        if(root == NULL) {
16            return;
17        }
18
19        trav(root->left, inorder);
20        inorder.push_back(root->val);
21        trav(root->right, inorder);
22    }
23
24    TreeNode* buildTree(TreeNode* &root, vector<int> &inorder, int st, int end) {
25        if(st > end) {
26            return NULL;
27        }
28
29        int mid = st + (end-st)/2;
30
31        if(root == NULL) {
32            root = new TreeNode(inorder[mid]);
33        }
34
35        root->left = buildTree(root->left, inorder, st, mid - 1);
36        root->right = buildTree(root->right, inorder, mid + 1, end);
37
38        return root;
39    }
40
41    TreeNode* balanceBST(TreeNode* root) {
42        vector<int> inorder;
43        trav(root, inorder);
44
45        TreeNode* ans = NULL;
46
47        TreeNode* ret = buildTree(ans, inorder, 0, inorder.size()-1);
48
49        return ret;
50    }
51};