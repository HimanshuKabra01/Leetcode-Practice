// Last updated: 8/9/2026, 12:41:05 PM
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
    TreeNode* buildTree(TreeNode* &root, vector<int> &nums, int st, int end) {
        if(st > end) {
            return NULL;
        }
        int mid = st + (end-st)/2;

        if(root == NULL) {
            root = new TreeNode(nums[mid]);
        }

        root->left = buildTree(root->left, nums, st, mid - 1);
        root->right = buildTree(root->right, nums, mid + 1, end);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;

        TreeNode* ans = buildTree(root, nums, 0, nums.size() - 1);

        return ans;
    }
};