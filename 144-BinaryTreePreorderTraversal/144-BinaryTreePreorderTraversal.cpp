// Last updated: 2/7/2026, 2:49:03 PM
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
14    // void preorder(TreeNode* root, vector<int>& ans) {
15    //     if(root == NULL) {
16    //         return;
17    //     }
18
19    //     ans.push_back(root->val);
20    //     preorder(root->left, ans);
21    //     preorder(root->right, ans);
22    // }
23    vector<int> preorderTraversal(TreeNode* root) {
24        vector<int> ans;
25
26        // preorder(root, ans);
27
28        // MORRIS PREORDER TRAVERSAL:-
29
30        TreeNode* curr = root;
31
32        while(curr != NULL) {
33           if(curr->left == NULL) {
34            ans.push_back(curr->val);
35            curr = curr->right;
36           } else {
37            TreeNode* ip = curr->left;
38            while(ip->right != NULL && ip->right != curr) {
39                ip = ip->right;
40            }
41            if(ip->right == NULL) {
42                ans.push_back(curr->val);
43                ip->right = curr;
44                curr = curr->left;
45            } else {
46                ip->right = NULL;
47                curr = curr->right;
48            }
49           } 
50        }
51
52        return ans;
53    }
54};