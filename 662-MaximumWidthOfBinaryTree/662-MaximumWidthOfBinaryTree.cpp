// Last updated: 8/9/2026, 12:36:26 PM
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
    int widthOfBinaryTree(TreeNode* root) {
       deque<pair<TreeNode*, unsigned long long int>> q;
       q.push_back({root, 0});

       int ans = 0;

       while(!q.empty()) {
            int size = q.size();
            unsigned long long int idx = q.front().second;
            unsigned long long int end = q.back().second;

            int subAns = end - idx + 1;
            ans = max(subAns, ans);

            for(int i = 0; i < size; i++) {
                TreeNode* curr = q.front().first;
                idx = q.front().second;
                q.pop_front();

                unsigned long long int left = 2 * idx +1;
                unsigned long long int right = 2 * idx + 2;

                if(curr->left != NULL) {
                    q.push_back({curr->left, left});
                }

                if(curr->right != NULL) {
                    q.push_back({curr->right, right});
                }
            }
       }

       return ans; 
    }
};