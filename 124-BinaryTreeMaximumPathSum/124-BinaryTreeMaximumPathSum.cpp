// Last updated: 1/24/2026, 3:15:44 PM
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
14    unordered_set<int> s;
15    void rec(TreeNode* root, int &ans) {
16        if(root == NULL){
17            return;
18        }
19
20        ans += root->val;
21
22        if(root->left == NULL && root->right == NULL) {
23            s.insert(ans);
24        }
25
26        rec(root->left, ans);
27        rec(root->right, ans);
28
29        ans -= root->val;
30    }
31    bool hasPathSum(TreeNode* root, int targetSum) {
32        int ans = 0;
33
34        rec(root, ans);
35
36        if(s.find(targetSum) == s.end()) {
37            return false;
38        } else {
39            return true;
40        }
41    }
42};