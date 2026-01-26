// Last updated: 1/26/2026, 5:56:45 PM
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
14    map<int, int> m;
15    void trav(TreeNode* root, int level) {
16        if(root == NULL){
17            return;
18        }
19
20        if(m.find(level) == m.end()) {
21            m[level] = root->val;
22        }
23
24        trav(root->right, level + 1);
25        trav(root->left, level +1);
26    }
27    vector<int> rightSideView(TreeNode* root) {
28        vector<int> ans;
29
30        trav(root, 0);
31
32        for(auto &entry : m) {
33            ans.push_back(entry.second);
34        }
35
36        return ans;
37    }
38};