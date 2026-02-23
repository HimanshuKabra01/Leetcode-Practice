// Last updated: 2/24/2026, 2:03:07 AM
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
12class BSTIterator {
13public:
14    stack<TreeNode*> st;
15
16    void pushlefts(TreeNode* root) {
17        while(root != NULL) {
18            st.push(root);
19            root = root->left;
20        }
21    }
22
23    BSTIterator(TreeNode* root) {
24        pushlefts(root);
25    }
26    
27    int next() {
28        TreeNode* ans = st.top();
29        st.pop();
30
31        if(ans->right != NULL) {
32            pushlefts(ans->right);
33        }
34
35        return ans->val;
36    }
37    
38    bool hasNext() {
39        return st.size() > 0;
40    }
41};
42
43/**
44 * Your BSTIterator object will be instantiated and called as such:
45 * BSTIterator* obj = new BSTIterator(root);
46 * int param_1 = obj->next();
47 * bool param_2 = obj->hasNext();
48 */