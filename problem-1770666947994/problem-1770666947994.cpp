// Last updated: 2/10/2026, 1:25:47 AM
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
14    void inO(TreeNode* root, vector<int>& inorder) {
15        if(root == NULL) {
16            return;
17        }
18
19        inO(root->left, inorder);
20        inorder.push_back(root->val);
21        inO(root->right, inorder);
22    }
23
24    int kthSmallest(TreeNode* root, int k) {
25       vector<int> inorder;
26
27       inO(root, inorder);
28
29       return inorder[k-1]; 
30    }
31};