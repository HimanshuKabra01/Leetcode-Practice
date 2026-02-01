// Last updated: 2/2/2026, 2:00:21 AM
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
14    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int &idx, int inSt, int inEnd) {
15        if(inEnd < inSt) {
16            return NULL;
17        }
18        
19        TreeNode* root = new TreeNode(preorder[idx]);
20
21        int inIdx = -1;
22        for(int i = 0; i < inorder.size(); i++) {
23            if(preorder[idx] == inorder[i]) {
24                inIdx = i;
25                break;
26            }
27        }
28        idx++;
29
30        root->left = makeTree(preorder, inorder, idx, inSt, inIdx - 1);
31        root->right = makeTree(preorder, inorder, idx, inIdx + 1, inEnd);
32
33        return root;
34    } 
35    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
36        int idx = 0;
37        TreeNode* ans = makeTree(preorder, inorder, idx, 0, inorder.size()-1);
38
39        return ans;
40    }
41};