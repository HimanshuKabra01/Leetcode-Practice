// Last updated: 4/15/2026, 1:39:05 AM
1/*
2// Definition for a Node.
3class Node {
4public:
5    int val;
6    vector<Node*> neighbors;
7    Node() {
8        val = 0;
9        neighbors = vector<Node*>();
10    }
11    Node(int _val) {
12        val = _val;
13        neighbors = vector<Node*>();
14    }
15    Node(int _val, vector<Node*> _neighbors) {
16        val = _val;
17        neighbors = _neighbors;
18    }
19};
20*/
21
22class Solution {
23public:
24    Node* cloneGraph(Node* node) {
25        if(node == NULL) {
26            return NULL;
27        }
28
29        queue<Node*> q;
30        q.push(node);
31
32        unordered_map<Node*, Node*> m;
33
34        Node* newNode = new Node(node->val);
35        m[node] = newNode;
36
37        while(!q.empty()) {
38            Node* curr = q.front();
39            q.pop();
40
41            for(auto x : curr->neighbors) {
42                if(!m.count(x)) { 
43                    q.push(x);
44
45                    Node* nNode = new Node(x->val);
46
47                    m[x] = nNode;
48                }
49
50                m[x]->neighbors.push_back(m[curr]);
51            }
52        }
53
54        return newNode;
55    }
56};