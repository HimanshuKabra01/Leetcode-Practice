// Last updated: 9/10/2026, 3:24:50 PM
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
14    int ans = 0;
15    pair<int, int> trav(TreeNode* root) {
16        if(root == NULL) {
17            return {0, 0};
18        }
19
20        pair<int, int> l = trav(root->left);
21        pair<int, int> r = trav(root->right);
22
23        int curr = l.first + r.first + root->val;
24        int cout = l.second + r.second + 1;
25
26        if(curr/cout == root->val) {
27            ans++;
28        }
29
30        return {curr, cout};
31    }
32    int averageOfSubtree(TreeNode* root) {
33        
34        trav(root);
35
36        return ans;
37    }
38};