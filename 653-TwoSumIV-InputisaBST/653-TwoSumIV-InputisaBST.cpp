// Last updated: 2/14/2026, 4:20:36 PM
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
14    bool isPossible = false;
15    unordered_set<int> s;
16    void helper(TreeNode* root, int k) {
17        if(root == NULL) {
18            return;
19        }
20
21        helper(root->left, k);
22
23        int needed = k - root->val;
24
25        if(s.count(needed)) {
26            isPossible = true;
27        } else {
28            s.insert(root->val);
29        }
30
31        helper(root->right, k);
32        return;
33    }
34    bool findTarget(TreeNode* root, int k) {
35
36        helper(root, k);
37
38        return isPossible; 
39    }
40};