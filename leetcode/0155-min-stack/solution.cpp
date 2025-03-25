class MinStack {
public:
    MinStack() {
        
    }

    vector<pair<int,int>>vp = {{INT_MAX,INT_MAX}};
    
    void push(int val) {
        vp.push_back({val,min(val,vp.back().second)});
    }
    
    void pop() {
        vp.pop_back();
    }
    
    int top() {
        return vp.back().first;
        
    }
    
    int getMin() {
        return vp.back().second;
        
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
