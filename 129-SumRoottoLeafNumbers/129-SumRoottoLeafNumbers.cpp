// Last updated: 1/24/2026, 3:04:43 PM
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
14    void rec(TreeNode* root, int &ans, string &curr) {
15        if(root == NULL){
16            return;
17        }
18
19        curr += to_string(root->val);
20
21        if(root->left == NULL && root->right == NULL) {
22            ans += stoi(curr);
23        }
24
25        rec(root->left, ans, curr);
26        rec(root->right, ans, curr);
27
28        curr.pop_back();
29    }
30    int sumNumbers(TreeNode* root) {
31        int ans = 0;
32        string curr = "";
33
34        rec(root, ans, curr);
35
36        return ans;
37    }
38};