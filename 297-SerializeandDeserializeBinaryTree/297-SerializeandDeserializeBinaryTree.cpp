// Last updated: 3/1/2026, 1:06:00 AM
1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
8 * };
9 */
10class Codec {
11public:
12
13    void pre(TreeNode* root, string &ans) {
14        if(root == NULL) {
15            ans += "null,";
16            return;
17        }
18
19        ans += to_string(root->val) + ",";
20
21        pre(root->left, ans);
22        pre(root->right, ans);
23    }
24
25    string serialize(TreeNode* root) {
26       string ans = "";
27
28       pre(root, ans) ;
29
30       return ans;
31    }
32
33    TreeNode* buildTree(vector<string> &nodes, int &idx) {
34        string val = nodes[idx++];
35
36        if(val == "null") {
37            return NULL;
38        }
39
40        TreeNode* root = new TreeNode(stoi(val));
41
42        root->left = buildTree(nodes, idx);
43        root->right = buildTree(nodes, idx);
44
45        return root;
46    }
47
48    TreeNode* deserialize(string data) {
49       vector<string> nodes;
50
51       for(int i = 0; i < data.size(); i++) {
52        string curr = "";
53
54        while(i < data.size() && data[i] != ',') {
55
56            curr += data[i];
57
58            i++;
59        }
60        if(curr != "") nodes.push_back(curr);
61       }
62        int idx = 0;
63        return buildTree(nodes, idx);
64    }
65};
66
67// Your Codec object will be instantiated and called as such:
68// Codec ser, deser;
69// TreeNode* ans = deser.deserialize(ser.serialize(root));