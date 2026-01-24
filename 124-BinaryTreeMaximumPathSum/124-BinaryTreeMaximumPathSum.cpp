// Last updated: 1/24/2026, 3:23:38 PM
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
14    void rec(TreeNode* root, vector<vector<int>> &ans, vector<int> &subAns, int targetSum, int &currSum) {
15        if(root == NULL){
16            return;
17        }
18
19        currSum += root->val;
20        subAns.push_back(root->val);
21
22        if(root->left == NULL && root->right == NULL) {
23            if(currSum == targetSum) {
24                ans.push_back({subAns});
25            }
26        }
27
28        rec(root->left, ans, subAns, targetSum, currSum);
29        rec(root->right, ans, subAns, targetSum, currSum);
30
31        currSum -= root->val;
32        subAns.pop_back();
33    }
34    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
35        vector<vector<int>> ans;
36        vector<int> subAns;
37        int currSum = 0;
38
39        rec(root, ans, subAns, targetSum, currSum);
40
41        return ans;
42    }
43};