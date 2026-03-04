// Last updated: 3/4/2026, 1:11:43 PM
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
14    int subMax = INT_MIN;
15
16    int helper(TreeNode* root) {
17        if(root == NULL) {
18            return 0;
19        }
20
21        int left = helper(root->left);
22        int right = helper(root->right);
23
24        int sum = 0;
25        if(left < 0 && right < 0) {
26            sum = root->val;
27        } else if(left < 0) {
28            sum = root->val + right;
29        } else if(right < 0) {
30            sum = root->val + left;
31        } else {
32            sum = left + root->val + right;
33        }
34
35        if(sum > subMax) {
36            subMax = sum;
37        }
38
39        if((root->val + max(left, right)) < root->val) {
40            return root->val;
41        } else {
42            return root->val + max(left, right);
43        }
44    }
45    int maxPathSum(TreeNode* root) {
46        int one = helper(root);
47
48        return max(one, subMax);
49    }
50};