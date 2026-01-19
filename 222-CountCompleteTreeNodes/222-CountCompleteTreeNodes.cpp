// Last updated: 1/20/2026, 12:57:38 AM
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
14    void trav(TreeNode* root, int &ans) {
15        if(root == NULL){
16            return;
17        }
18
19        ans++;
20        trav(root->left, ans);
21        trav(root->right, ans);
22    }
23
24    int countNodes(TreeNode* root) {
25        int ans = 0;
26
27        trav(root, ans);
28
29        return ans;
30    }
31};