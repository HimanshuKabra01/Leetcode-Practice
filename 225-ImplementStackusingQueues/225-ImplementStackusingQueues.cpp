// Last updated: 1/13/2026, 6:59:53 PM
1class MyStack {
2public:
3    queue<int> q;
4    MyStack() {
5        
6    }
7    
8    void push(int x) {
9        int size = q.size();
10
11        q.push(x);
12
13        for(int i = 0; i < size; i++) {
14            q.push(q.front());
15            q.pop();
16        }
17    }
18    
19    int pop() {
20        if(empty()) return -1;
21
22        int val = q.front();
23        q.pop();
24        return val;
25    }
26    
27    int top() {
28        if(empty()) return -1;
29
30        return q.front();
31    }
32    
33    bool empty() {
34        return q.empty();
35    }
36};
37
38/**
39 * Your MyStack object will be instantiated and called as such:
40 * MyStack* obj = new MyStack();
41 * obj->push(x);
42 * int param_2 = obj->pop();
43 * int param_3 = obj->top();
44 * bool param_4 = obj->empty();
45 */