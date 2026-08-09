// Last updated: 8/9/2026, 12:38:48 PM
class MyStack {
public:
    queue<int> q;
    MyStack() {
        
    }
    
    void push(int x) {
        int size = q.size();

        q.push(x);

        for(int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        if(empty()) return -1;

        int val = q.front();
        q.pop();
        return val;
    }
    
    int top() {
        if(empty()) return -1;

        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */