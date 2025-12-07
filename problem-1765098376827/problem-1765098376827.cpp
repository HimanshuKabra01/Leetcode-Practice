// Last updated: 12/7/2025, 2:36:16 PM
1class MinStack {
2public:
3    MinStack() {
4        
5    }
6
7    stack<long long int> st;
8    long long int minVal = INT_MIN;
9
10    void push(int val) {
11        if(st.empty()) {
12            st.push(val);
13            minVal = val;
14        } else {
15            if(val < minVal) {
16                st.push((long long)2*val - minVal);
17                minVal = val;
18            } else {
19                st.push(val);
20            }
21        }
22    }
23    
24    void pop() {
25        if(st.top() < minVal) {
26            minVal = 2*minVal - st.top();
27        }
28
29        st.pop();
30    }
31    
32    int top() {
33        if(st.top() < minVal) {
34            return minVal;
35        } else {
36            return st.top();
37        }
38    }
39    
40    int getMin() {
41        return minVal;
42    }
43};
44
45/**
46 * Your MinStack object will be instantiated and called as such:
47 * MinStack* obj = new MinStack();
48 * obj->push(val);
49 * obj->pop();
50 * int param_3 = obj->top();
51 * int param_4 = obj->getMin();
52 */