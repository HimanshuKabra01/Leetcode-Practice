// Last updated: 2/18/2026, 1:44:11 AM
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
14    vector<vector<int>> levelOrderBottom(TreeNode* root) {
15        if(root == NULL) {
16            return {};
17        }
18        vector<vector<int>> ans;
19        vector<int> subAns;
20        queue<TreeNode*> q;
21        q.push(root);
22
23        q.push(NULL);
24
25        while(!q.empty()) {
26            TreeNode* curr = q.front();
27
28            q.pop();
29
30            if(curr == NULL) {
31                ans.push_back(subAns);
32                subAns.clear();
33
34                if(!q.empty()) {
35                    q.push(NULL);
36                    continue;
37                } else{
38                    break;
39                }
40            } else {
41                subAns.push_back(curr->val);
42            }
43
44            if(curr->left != NULL) {
45                q.push(curr->left);
46            }
47
48            if(curr->right != NULL) {
49                q.push(curr->right);
50            }
51        }
52
53        reverse(ans.begin(), ans.end());
54
55        return ans;
56    }
57};