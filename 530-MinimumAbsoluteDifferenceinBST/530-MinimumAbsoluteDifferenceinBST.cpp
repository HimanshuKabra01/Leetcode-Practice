// Last updated: 2/13/2026, 10:37:42 PM
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
14    void in(TreeNode* root, vector<int>& inorder) {
15        if(root == NULL) {
16            return;
17        } 
18
19        in(root->left, inorder);
20        inorder.push_back(root->val);
21        in(root->right, inorder);
22    }
23    int getMinimumDifference(TreeNode* root) {
24        vector<int> inorder;
25
26        in(root, inorder);
27        
28        int n = inorder.size();
29        vector<int> pref(n-1);
30        for(int i = 0; i < n-1; i++) {
31            pref[i] = inorder[i+1]-inorder[i];
32        }
33
34        sort(pref.begin(), pref.end());
35
36        return pref[0];
37    }
38};