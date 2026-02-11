// Last updated: 2/11/2026, 6:15:54 PM
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
14    TreeNode* buildTree(TreeNode* &root, vector<int> &nums, int st, int end) {
15        if(st > end) {
16            return NULL;
17        }
18        int mid = st + (end-st)/2;
19
20        if(root == NULL) {
21            root = new TreeNode(nums[mid]);
22        }
23
24        root->left = buildTree(root->left, nums, st, mid - 1);
25        root->right = buildTree(root->right, nums, mid + 1, end);
26
27        return root;
28    }
29    TreeNode* sortedArrayToBST(vector<int>& nums) {
30        TreeNode* root = NULL;
31
32        TreeNode* ans = buildTree(root, nums, 0, nums.size() - 1);
33
34        return ans;
35    }
36};