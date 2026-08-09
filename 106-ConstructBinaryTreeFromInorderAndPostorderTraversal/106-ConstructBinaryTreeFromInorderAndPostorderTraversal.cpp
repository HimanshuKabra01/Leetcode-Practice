// Last updated: 8/9/2026, 12:41:11 PM
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
    TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int &idx, int left, int right) {

        if(left > right) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[idx]);

        int inIdx = -1;
        for(int i = 0; i < inorder.size(); i++) {
            if(postorder[idx] == inorder[i]) {
                inIdx = i;
                break;
            }
        }

        idx--;

        root->right = helper(inorder, postorder, idx, inIdx + 1, right);
        root->left = helper(inorder, postorder, idx, left, inIdx - 1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int idx = postorder.size()-1;

        return helper(inorder, postorder, idx, 0, inorder.size()-1);
    }
};