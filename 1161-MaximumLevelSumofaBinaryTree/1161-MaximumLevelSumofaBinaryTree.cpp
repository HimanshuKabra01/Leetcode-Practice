// Last updated: 2/8/2026, 10:38:54 AM
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
14    int maxLevelSum(TreeNode* root) {
15        int ans = INT_MIN;
16        int lvlAns = 0;
17        int lvl = 0;
18        queue<TreeNode*> q;
19        q.push(root);
20        q.push(NULL);
21
22        int currAns = 0;
23        while(!q.empty()) {
24            TreeNode* curr = q.front();
25
26            q.pop();
27            if(curr == NULL) {
28                lvl++;
29                if(currAns > ans) {
30                    ans = currAns;
31                    lvlAns = lvl;
32                }
33
34                currAns = 0;
35                if(!q.empty()) {
36                    q.push(NULL);
37                    continue;
38                } else {
39                    break;
40                }
41            } else {
42                currAns += curr->val;
43            }
44
45            if(curr->left != NULL) {
46                q.push(curr->left);
47            }
48            if(curr->right != NULL) {
49                q.push(curr->right);
50            }
51        }
52
53        return lvlAns;
54    }
55};