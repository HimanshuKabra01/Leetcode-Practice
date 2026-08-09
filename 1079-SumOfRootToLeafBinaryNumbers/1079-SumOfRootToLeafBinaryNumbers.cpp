// Last updated: 8/9/2026, 12:34:22 PM
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
    void rec(TreeNode* root, vector<string> &nums, string &s) {
        if(root == NULL) {
            return;
        }

        s += to_string(root->val);

        if(root->left == NULL && root->right == NULL) {
            nums.push_back(s);
        }

        rec(root->left, nums, s);
        rec(root->right, nums, s);

        int n = s.size();
        s.resize(n-1);
    }

    int getNum(string s) {
        int finalNum = 0;
        for(int i = 0; i < s.size(); i++) {
            int num = s[s.size() - i - 1] - '0';
            finalNum += pow(2, i) * num;
        }

        return finalNum;
    }

    int sumRootToLeaf(TreeNode* root) {
        vector<string> nums;
        string s = "";

        rec(root, nums, s);

        int ans = 0;
        for(int i = 0; i < nums.size(); i++) {
            int num = getNum(nums[i]);

            ans += num;
        }

        return ans;
    }
};