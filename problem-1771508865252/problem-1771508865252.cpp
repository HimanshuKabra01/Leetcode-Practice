// Last updated: 2/19/2026, 7:17:45 PM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    Node* left;
7    Node* right;
8    Node* next;
9
10    Node() : val(0), left(NULL), right(NULL), next(NULL) {}
11
12    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
13
14    Node(int _val, Node* _left, Node* _right, Node* _next)
15        : val(_val), left(_left), right(_right), next(_next) {}
16};
17*/
18
19class Solution {
20public:
21    Node* connect(Node* root) {
22        if(root == NULL) {
23            return NULL;
24        }
25        
26        queue<Node*> q;
27        q.push(root);
28
29        while(!q.empty()) {
30            int size = q.size();
31            Node* prev = NULL;
32
33            for(int i = 0; i < size; i++) {
34                Node* curr = q.front();
35                q.pop();
36
37                if(prev != NULL) {
38                    prev->next = curr;
39                }
40
41                prev = curr;
42
43                if(curr->left != NULL) {
44                    q.push(curr->left);
45                }
46
47                if(curr->right != NULL) {
48                    q.push(curr->right);
49                }
50            }
51        }
52
53        return root;
54    }
55};