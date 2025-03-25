class MyQueue {
public:
    MyQueue() {
        
    }

    stack<int>*st1 = new stack<int>(), *st2 = new stack<int>();

    
    void push(int x) {
        st1->push(x);  
        // cout<<st1->top()<<" ";      
    }
    
    int pop() {
        cout<<st1->top()<<" ";
        int ele = -1;
        while(st1->size()>1){
            ele = st1->top();
            st1->pop();
            st2->push(ele);
            // cout<<ele<<" ";
        }
        ele = st1->top();
        st1->pop();

        while(st2->size()>0){
            st1->push(st2->top());
            st2->pop();
        }

        return ele;
    }
    
    int peek() {
        int ele=-1;

        while(st1->size()>0){
            ele=st1->top();
            st1->pop();
            st2->push(ele);
        }

        while(st2->size()>0){
            st1->push(st2->top());
            st2->pop();
        }

        return ele;
    }
    
    bool empty() {
        return st1->size()==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
