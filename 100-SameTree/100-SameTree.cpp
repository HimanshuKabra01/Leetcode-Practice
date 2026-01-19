// Last updated: 1/19/2026, 11:25:35 PM
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
14    void pre(TreeNode* root, vector<string> &ans) {
15        if(root == NULL){
16            ans.push_back("null");
17            return;
18        }
19
20        ans.push_back(to_string(root->val));
21        pre(root->left, ans);
22        pre(root->right, ans);
23    } 
24    bool isSameTree(TreeNode* p, TreeNode* q) {
25        vector<string> a;
26        vector<string> b;
27
28        pre(p, a);
29        pre(q, b);
30
31        if(a == b) {
32            return true;
33        } else {
34            return false;
35        }
36    }
37};