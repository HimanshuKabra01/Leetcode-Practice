// Last updated: 12/7/2025, 1:34:41 PM
1class MinStack {
2public:
3    MinStack() {
4        
5    }
6    stack<pair<int, int>> st;
7    void push(int val) {
8      if(st.empty()) {
9        st.push({val, val});
10      } else {
11        int minVal = min(val, st.top().second);
12        st.push({val, minVal});
13      }   
14    }
15    
16    void pop() {
17        st.pop();
18    }
19    
20    int top() {
21        return st.top().first;
22    }
23    
24    int getMin() {
25        return st.top().second;
26    }
27};
28
29/**
30 * Your MinStack object will be instantiated and called as such:
31 * MinStack* obj = new MinStack();
32 * obj->push(val);
33 * obj->pop();
34 * int param_3 = obj->top();
35 * int param_4 = obj->getMin();
36 */