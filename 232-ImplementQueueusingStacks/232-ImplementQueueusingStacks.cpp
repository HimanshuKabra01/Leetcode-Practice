// Last updated: 1/13/2026, 7:47:20 PM
1class MyQueue {
2public:
3    stack<int> st1;
4    stack<int> st2;
5    MyQueue() {
6        
7    }
8    
9    void push(int x) {
10        st1.push(x);
11    }
12    
13    int pop() {
14        if(empty()) return -1;
15
16        int val = peek();
17        st2.pop();
18        return val;
19    }
20    
21    int peek() {
22        if(st2.empty()){
23            while(!st1.empty()) {
24                st2.push(st1.top());
25                st1.pop();
26            }
27        }
28
29        return st2.top();
30    }
31    
32    bool empty() {
33        return st1.empty() && st2.empty();
34    }
35};
36
37/**
38 * Your MyQueue object will be instantiated and called as such:
39 * MyQueue* obj = new MyQueue();
40 * obj->push(x);
41 * int param_2 = obj->pop();
42 * int param_3 = obj->peek();
43 * bool param_4 = obj->empty();
44 */