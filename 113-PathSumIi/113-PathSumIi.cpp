// Last updated: 8/9/2026, 12:40:56 PM
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
    void rec(TreeNode* root, vector<vector<int>> &ans, vector<int> &subAns, int targetSum, int &currSum) {
        if(root == NULL){
            return;
        }

        currSum += root->val;
        subAns.push_back(root->val);

        if(root->left == NULL && root->right == NULL) {
            if(currSum == targetSum) {
                ans.push_back({subAns});
            }
        }

        rec(root->left, ans, subAns, targetSum, currSum);
        rec(root->right, ans, subAns, targetSum, currSum);

        currSum -= root->val;
        subAns.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> subAns;
        int currSum = 0;

        rec(root, ans, subAns, targetSum, currSum);

        return ans;
    }
};