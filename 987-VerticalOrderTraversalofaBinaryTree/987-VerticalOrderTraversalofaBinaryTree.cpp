// Last updated: 1/26/2026, 4:39:20 PM
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
14    void trav(TreeNode* root, vector<vector<int>> &ans) {
15        queue<pair<TreeNode*, pair<int, int>>> q;
16        q.push({root, {0,0}});
17        map<int, map<int,vector<int>>> m;
18
19        while(!q.empty()) {
20            TreeNode* curr = q.front().first;
21            int currHD = q.front().second.first;
22            int level = q.front().second.second;
23
24            q.pop();
25
26            m[currHD][level].push_back(curr->val);
27
28            if(curr->left != NULL) {
29                q.push({curr->left, {currHD - 1, level + 1}});
30            }
31
32            if(curr->right != NULL) {
33                q.push({curr->right, {currHD + 1, level + 1}});
34            }
35        }
36
37        for(auto &entry : m) {
38            vector<int> cols;
39
40            for(auto &it : entry.second) {
41                sort(it.second.begin(), it.second.end());
42
43                cols.insert(cols.end(), it.second.begin(), it.second.end());
44            }
45
46            ans.push_back(cols);
47        }
48    }
49
50    vector<vector<int>> verticalTraversal(TreeNode* root) {
51        vector<vector<int>> ans;
52
53        trav(root, ans);
54
55        return ans;
56    }
57};