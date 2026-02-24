// Last updated: 2/24/2026, 11:44:51 AM
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
14    void rec(TreeNode* root, vector<string> &nums, string &s) {
15        if(root == NULL) {
16            return;
17        }
18
19        s += to_string(root->val);
20
21        if(root->left == NULL && root->right == NULL) {
22            nums.push_back(s);
23        }
24
25        rec(root->left, nums, s);
26        rec(root->right, nums, s);
27
28        int n = s.size();
29        s.resize(n-1);
30    }
31
32    int getNum(string s) {
33        int finalNum = 0;
34        for(int i = 0; i < s.size(); i++) {
35            int num = s[s.size() - i - 1] - '0';
36            finalNum += pow(2, i) * num;
37        }
38
39        return finalNum;
40    }
41
42    int sumRootToLeaf(TreeNode* root) {
43        vector<string> nums;
44        string s = "";
45
46        rec(root, nums, s);
47
48        int ans = 0;
49        for(int i = 0; i < nums.size(); i++) {
50            int num = getNum(nums[i]);
51
52            ans += num;
53        }
54
55        return ans;
56    }
57};