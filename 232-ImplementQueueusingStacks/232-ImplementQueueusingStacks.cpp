// Last updated: 1/13/2026, 7:40:28 PM
1class MyQueue {
2public:
3    stack<int> st1;
4    stack<int> st2;
5    MyQueue() {
6        
7    }
8    
9    void push(int x) {
10        while(!st1.empty()){
11            st2.push(st1.top());
12            st1.pop();
13        }
14
15        st1.push(x);
16
17        while(!st2.empty()) {
18            st1.push(st2.top());
19            st2.pop();
20        }
21    }
22    
23    int pop() {
24        if(empty()) return -1;
25
26        int val = st1.top();
27        st1.pop();
28        return val;
29    }
30    
31    int peek() {
32        if(empty()) return -1;
33
34        return st1.top();
35    }
36    
37    bool empty() {
38        return st1.size() == 0;
39    }
40};
41
42/**
43 * Your MyQueue object will be instantiated and called as such:
44 * MyQueue* obj = new MyQueue();
45 * obj->push(x);
46 * int param_2 = obj->pop();
47 * int param_3 = obj->peek();
48 * bool param_4 = obj->empty();
49 */