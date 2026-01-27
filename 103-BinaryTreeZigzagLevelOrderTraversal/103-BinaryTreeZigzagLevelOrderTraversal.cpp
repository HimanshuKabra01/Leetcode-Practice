// Last updated: 1/27/2026, 8:25:59 PM
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
14    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
15        if(root == NULL) {
16            return {};
17        }
18
19        vector<vector<int>> ans;
20        queue<TreeNode*> q;
21        int level = 0;
22        q.push(root);
23        q.push(NULL);
24        vector<int> subAns;
25
26        while(!q.empty()) {
27            TreeNode* curr = q.front();
28            q.pop();
29
30            if(curr == NULL) {
31                if(level % 2 != 0) {
32                    reverse(subAns.begin(), subAns.end());
33                }
34
35                ans.push_back(subAns);
36                subAns.clear();
37                if(!q.empty()) {
38                    q.push(NULL);
39                    level++;
40                    continue;
41                } else {
42                    break;
43                }
44            } else {
45                subAns.push_back(curr->val);
46            }
47
48            if(curr->left != NULL){
49                q.push(curr->left);
50            }
51
52            if(curr->right != NULL) {
53                q.push(curr->right);
54            }
55        }
56
57        return ans;
58    }
59};