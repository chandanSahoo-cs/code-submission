class MyStack {
public:
    MyStack() {
        
    }
    queue<int>*q1=new queue<int>(),*q2=new queue<int>();

    void push(int x) {
        q1->push(x);
    }
    
    int pop() {
        if(q1->size()==0) return -1;
        int ele=-1;
        while(q1->size()>1){
            ele = q1->front();
            q1->pop();
            q2->push(ele);
        }
        ele = q1->front();
        q1->pop();
        swap(q1,q2);
        return ele;
        
    }
    
    int top() {
        int ele=-1;
        while(q1->size()>0){
            ele = q1->front();
            q1->pop();
            q2->push(ele);
        }
        swap(q1,q2);

        return ele;
    }
    
    bool empty() {
        return q1->size()==0;
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
