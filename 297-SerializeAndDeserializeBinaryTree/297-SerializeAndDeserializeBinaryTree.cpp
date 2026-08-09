// Last updated: 8/9/2026, 12:38:02 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    void pre(TreeNode* root, string &ans) {
        if(root == NULL) {
            ans += "null,";
            return;
        }

        ans += to_string(root->val) + ",";

        pre(root->left, ans);
        pre(root->right, ans);
    }

    string serialize(TreeNode* root) {
       string ans = "";

       pre(root, ans) ;

       return ans;
    }

    TreeNode* buildTree(vector<string> &nodes, int &idx) {
        string val = nodes[idx++];

        if(val == "null") {
            return NULL;
        }

        TreeNode* root = new TreeNode(stoi(val));

        root->left = buildTree(nodes, idx);
        root->right = buildTree(nodes, idx);

        return root;
    }

    TreeNode* deserialize(string data) {
       vector<string> nodes;

       for(int i = 0; i < data.size(); i++) {
        string curr = "";

        while(i < data.size() && data[i] != ',') {

            curr += data[i];

            i++;
        }
        if(curr != "") nodes.push_back(curr);
       }
        int idx = 0;
        return buildTree(nodes, idx);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));