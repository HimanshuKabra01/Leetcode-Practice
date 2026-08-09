// Last updated: 8/9/2026, 12:41:08 PM
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == NULL) {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> subAns;
        queue<TreeNode*> q;
        q.push(root);

        q.push(NULL);

        while(!q.empty()) {
            TreeNode* curr = q.front();

            q.pop();

            if(curr == NULL) {
                ans.push_back(subAns);
                subAns.clear();

                if(!q.empty()) {
                    q.push(NULL);
                    continue;
                } else{
                    break;
                }
            } else {
                subAns.push_back(curr->val);
            }

            if(curr->left != NULL) {
                q.push(curr->left);
            }

            if(curr->right != NULL) {
                q.push(curr->right);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};