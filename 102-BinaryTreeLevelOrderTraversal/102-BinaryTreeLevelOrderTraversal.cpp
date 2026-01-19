// Last updated: 1/19/2026, 6:45:19 PM
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
14    vector<vector<int>> levelOrder(TreeNode* root) {
15        if(root == NULL) {
16            return {};
17        }
18        vector<vector<int>> ans;
19        queue<TreeNode*> q;
20        q.push(root);
21        q.push(NULL);
22
23        vector<int> subans;
24        while(q.size() > 0) {
25            TreeNode* curr = q.front();
26            q.pop();
27
28            if(curr == NULL) {
29                    ans.push_back(subans);
30                    subans.clear();
31                if(!q.empty()){
32                    q.push(NULL);
33                    continue;
34                } else {
35                    break;
36                }
37            } else {
38                subans.push_back(curr->val);
39            }
40
41            if(curr->left != NULL){
42                q.push(curr->left);
43            }
44
45            if(curr->right != NULL){
46                q.push(curr->right);
47            }
48        }
49
50        return ans;
51    }
52};