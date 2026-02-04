// Last updated: 2/4/2026, 3:43:23 PM
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
14    void helper(TreeNode* root, string &onePath, vector<string>& ans) {
15        if(root == NULL) {
16            return;
17        }
18
19        int len = onePath.length();
20
21        if(root->left == NULL && root->right == NULL) {
22            onePath += to_string(root->val);
23            ans.push_back(onePath);
24        }
25
26        onePath += to_string(root->val);
27        onePath += "->";
28
29        helper(root->left, onePath, ans);
30        helper(root->right, onePath, ans);
31
32        onePath.resize(len);
33    }
34    vector<string> binaryTreePaths(TreeNode* root) {
35        vector<string> ans;
36        string onePath = "";
37
38        helper(root, onePath, ans);
39
40        return ans;
41    }
42};