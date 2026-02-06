// Last updated: 2/7/2026, 1:47:55 AM
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
14    // void inorder(TreeNode* root, vector<int>& ans) {
15    //     if(root == NULL) {
16    //         return;
17    //     }
18
19    //     inorder(root->left, ans);
20    //     ans.push_back(root->val);
21    //     inorder(root->right, ans);
22    // }
23
24    vector<int> inorderTraversal(TreeNode* root) {
25        vector<int> ans;
26
27        // inorder(root, ans);
28
29        //MORRIS INORDER TRAVERSAL :-
30
31        TreeNode* curr = root;
32
33        while(curr != NULL) {
34            if(curr->left == NULL) {
35                ans.push_back(curr->val);
36                curr = curr->right;
37            } else {
38                TreeNode* ip = curr->left;
39                while(ip->right != NULL && ip->right != curr) {
40                    ip = ip->right;
41                }
42
43                if(ip->right == NULL) {
44                    ip->right = curr; // create thread
45                    curr = curr->left;
46                } else {
47                    ip->right = NULL; //delete thread
48                    ans.push_back(curr->val);
49                    curr = curr->right;
50                }
51            }
52        }
53
54        return ans;
55    }
56};