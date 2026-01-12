// Last updated: 1/12/2026, 4:48:28 PM
1class LRUCache {
2public:
3    class Node {
4    public:
5        int key, val;
6
7        Node* next;
8        Node* prev;
9
10        Node(int k, int v) {
11            key = k;
12            val = v;
13
14            next = prev = NULL;
15        }
16    };
17
18    Node* head = new Node(-1,-1);
19    Node* tail = new Node(-1,-1);
20    
21    unordered_map<int, Node*> m;
22    int limit;
23
24    void addNode(Node* newNode) {
25        Node* temp = head->next;
26
27        head->next = newNode;
28        temp->prev = newNode;
29
30        newNode->next = temp;
31        newNode->prev = head;
32    }
33
34    void delNode(Node* oldNode) {
35        Node* oldNext = oldNode->next;
36        Node* oldPrev = oldNode->prev;
37
38        oldPrev->next = oldNext;
39        oldNext->prev = oldPrev;
40    }
41
42    LRUCache(int capacity) {
43        limit = capacity;
44
45        head->next = tail;
46        tail->prev = head;
47    }
48    
49    int get(int key) {
50        if(m.find(key) == m.end()) return -1;
51
52        Node* ansNode = m[key];
53        int ans = ansNode->val;
54
55        m.erase(key);
56        delNode(ansNode);
57
58        addNode(ansNode);
59        m[key] = ansNode;
60
61        return ans;
62    }
63    
64    void put(int key, int value) {
65        if(m.find(key) != m.end()) {
66            Node* oldNode = m[key];
67            delNode(oldNode);
68            m.erase(key);
69        }
70
71        if(m.size() == limit) {
72            m.erase(tail->prev->key);
73            delNode(tail->prev);
74        }
75
76        Node* newNode = new Node(key, value);
77        addNode(newNode);
78        m[key] = newNode;
79    }
80};
81
82/**
83 * Your LRUCache object will be instantiated and called as such:
84 * LRUCache* obj = new LRUCache(capacity);
85 * int param_1 = obj->get(key);
86 * obj->put(key,value);
87 */