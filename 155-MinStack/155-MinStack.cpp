// Last updated: 8/9/2026, 12:39:41 PM
class MinStack {
public:
    MinStack() {
        
    }

    stack<long long int> st;
    long long int minVal = INT_MIN;

    void push(int val) {
        if(st.empty()) {
            st.push(val);
            minVal = val;
        } else {
            if(val < minVal) {
                st.push((long long)2*val - minVal);
                minVal = val;
            } else {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top() < minVal) {
            minVal = 2*minVal - st.top();
        }

        st.pop();
    }
    
    int top() {
        if(st.top() < minVal) {
            return minVal;
        } else {
            return st.top();
        }
    }
    
    int getMin() {
        return minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */