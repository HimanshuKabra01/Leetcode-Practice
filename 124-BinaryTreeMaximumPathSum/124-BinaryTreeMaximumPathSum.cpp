// Last updated: 2/6/2026, 6:36:26 PM
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
14    int widthOfBinaryTree(TreeNode* root) {
15       deque<pair<TreeNode*, unsigned long long int>> q;
16       q.push_back({root, 0});
17
18       int ans = 0;
19
20       while(!q.empty()) {
21            int size = q.size();
22            unsigned long long int idx = q.front().second;
23            unsigned long long int end = q.back().second;
24
25            int subAns = end - idx + 1;
26            ans = max(subAns, ans);
27
28            for(int i = 0; i < size; i++) {
29                TreeNode* curr = q.front().first;
30                idx = q.front().second;
31                q.pop_front();
32
33                unsigned long long int left = 2 * idx +1;
34                unsigned long long int right = 2 * idx + 2;
35
36                if(curr->left != NULL) {
37                    q.push_back({curr->left, left});
38                }
39
40                if(curr->right != NULL) {
41                    q.push_back({curr->right, right});
42                }
43            }
44       }
45
46       return ans; 
47    }
48};