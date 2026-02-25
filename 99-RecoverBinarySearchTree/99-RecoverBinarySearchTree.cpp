// Last updated: 2/26/2026, 1:34:47 AM
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
14    void recoverTree(TreeNode* root) {
15        TreeNode* prev = NULL;
16        TreeNode* first = NULL;
17        TreeNode* second = NULL;
18
19        while(root != NULL) {
20            if(root->left == NULL) {
21                if(prev != NULL && prev->val > root->val) {
22                    if(!first) {
23                        first = prev;
24                    }
25
26                    second = root;
27                }
28
29                prev = root;
30                root = root->right;
31            } else {
32                TreeNode* IP = root->left;
33                while(IP->right != NULL && IP->right != root) {
34                    IP = IP->right;
35                }
36
37                if(IP->right == NULL) {
38                    IP->right = root;
39
40                    root = root->left;
41                } else {
42                    if(prev != NULL && prev->val > root->val) {
43                        if(!first) {
44                            first = prev;
45                        }
46
47                        second = root;
48                    }
49
50                    prev = root;
51                    IP->right = NULL;
52                    root = root->right;
53                }
54            }
55        }
56
57        if(first != NULL && second != NULL) {
58            int temp = first->val;
59            first->val = second->val;
60            second->val = temp;
61        }
62    }
63};