// Last updated: 8/9/2026, 12:41:16 PM
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
    TreeNode* makeTree(vector<int>& preorder, vector<int>& inorder, int &idx, int inSt, int inEnd) {
        if(inEnd < inSt) {
            return NULL;
        }
        
        TreeNode* root = new TreeNode(preorder[idx]);

        int inIdx = -1;
        for(int i = 0; i < inorder.size(); i++) {
            if(preorder[idx] == inorder[i]) {
                inIdx = i;
                break;
            }
        }
        idx++;

        root->left = makeTree(preorder, inorder, idx, inSt, inIdx - 1);
        root->right = makeTree(preorder, inorder, idx, inIdx + 1, inEnd);

        return root;
    } 
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        TreeNode* ans = makeTree(preorder, inorder, idx, 0, inorder.size()-1);

        return ans;
    }
};