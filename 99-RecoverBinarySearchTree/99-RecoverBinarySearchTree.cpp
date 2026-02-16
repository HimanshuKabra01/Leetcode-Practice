// Last updated: 2/16/2026, 11:31:09 PM
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
14    void trav(TreeNode* root, vector<int> &inorder) {
15        if(root == NULL) {
16            return;
17        }
18
19        trav(root->left, inorder);
20        inorder.push_back(root->val);
21        trav(root->right, inorder);        
22    }
23
24    void preorder(TreeNode* root, int &first, int &second) {
25        if(root == NULL) {
26            return;
27        }
28
29        if(root->val == first) {
30            root->val = second;
31        } else if(root->val == second) {
32            root->val = first;
33        }
34
35        preorder(root->left, first, second);
36        preorder(root->right, first, second);
37    }
38
39    void recoverTree(TreeNode* root) {
40        vector<int> inorder;
41
42        trav(root, inorder);
43
44        vector<int> sorted = inorder;
45
46        sort(sorted.begin(), sorted.end());
47
48        int first;
49        bool got = false;
50        int second;
51        
52        for(int i = 0; i < inorder.size(); i++) {
53           if(got == false && inorder[i] != sorted[i]) {
54            first = inorder[i];
55            got = true;
56           } 
57
58           if(got == true && inorder[i] != sorted[i]) {
59            second = inorder[i];
60           }
61        }
62
63        preorder(root, first, second);
64    }
65};