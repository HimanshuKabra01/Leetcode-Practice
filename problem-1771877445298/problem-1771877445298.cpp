// Last updated: 2/24/2026, 1:40:45 AM
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
14    vector<int> inorder;
15    int i = 0;
16
17    void trav(TreeNode* root) {
18        if(root == NULL) {
19            return;
20        }
21
22        trav(root->left);
23        inorder.push_back(root->val);
24        trav(root->right);
25    }
26
27    BSTIterator(TreeNode* root) {
28        trav(root);
29    }
30    
31    int next() {
32        int num = inorder[i];
33
34        i++;
35
36        return num;
37    }
38    
39    bool hasNext() {
40        if(i < inorder.size()) {
41            return true;
42        } else {
43            return false;
44        }
45    }
46};
47
48/**
49 * Your BSTIterator object will be instantiated and called as such:
50 * BSTIterator* obj = new BSTIterator(root);
51 * int param_1 = obj->next();
52 * bool param_2 = obj->hasNext();
53 */