// Last updated: 8/9/2026, 12:37:05 PM
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
    void in(TreeNode* root, vector<int>& inorder) {
        if(root == NULL) {
            return;
        } 

        in(root->left, inorder);
        inorder.push_back(root->val);
        in(root->right, inorder);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> inorder;

        in(root, inorder);
        
        int n = inorder.size();
        vector<int> pref(n-1);
        for(int i = 0; i < n-1; i++) {
            pref[i] = inorder[i+1]-inorder[i];
        }

        sort(pref.begin(), pref.end());

        return pref[0];
    }
};