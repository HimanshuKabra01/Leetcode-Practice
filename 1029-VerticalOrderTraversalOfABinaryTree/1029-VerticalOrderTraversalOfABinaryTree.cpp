// Last updated: 8/9/2026, 12:34:33 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void trav(TreeNode* root, vector<vector<int>> &ans) {
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0,0}});
        map<int, map<int,vector<int>>> m;

        while(!q.empty()) {
            TreeNode* curr = q.front().first;
            int currHD = q.front().second.first;
            int level = q.front().second.second;

            q.pop();

            m[currHD][level].push_back(curr->val);

            if(curr->left != NULL) {
                q.push({curr->left, {currHD - 1, level + 1}});
            }

            if(curr->right != NULL) {
                q.push({curr->right, {currHD + 1, level + 1}});
            }
        }

        for(auto &entry : m) {
            vector<int> cols;

            for(auto &it : entry.second) {
                sort(it.second.begin(), it.second.end());

                cols.insert(cols.end(), it.second.begin(), it.second.end());
            }

            ans.push_back(cols);
        }
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;

        trav(root, ans);

        return ans;
    }
};