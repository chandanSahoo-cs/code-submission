class MyStack {
public:
    queue<int>q;
    int sz;
    MyStack() {
        sz=0;
    }
    
    void push(int x) {
        q.push(x);

        for(int i=0;i<sz;i++){
            q.push(q.front());
            q.pop();
        }
        sz++;
    }
    
    int pop() {
        if(sz==0) return -1;
        int ele = q.front();
        q.pop();
        sz--;

        return ele;
    }
    
    int top() {
        if(sz==0) return -1;
        return q.front();
    }
    
    bool empty() {
        return sz==0;
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
