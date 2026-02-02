// Last updated: 2/2/2026, 3:42:10 PM
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
14    TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int &idx, int left, int right) {
15
16        if(left > right) {
17            return NULL;
18        }
19
20        TreeNode* root = new TreeNode(postorder[idx]);
21
22        int inIdx = -1;
23        for(int i = 0; i < inorder.size(); i++) {
24            if(postorder[idx] == inorder[i]) {
25                inIdx = i;
26                break;
27            }
28        }
29
30        idx--;
31
32        root->right = helper(inorder, postorder, idx, inIdx + 1, right);
33        root->left = helper(inorder, postorder, idx, left, inIdx - 1);
34
35        return root;
36    }
37    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
38        int idx = postorder.size()-1;
39
40        return helper(inorder, postorder, idx, 0, inorder.size()-1);
41    }
42};