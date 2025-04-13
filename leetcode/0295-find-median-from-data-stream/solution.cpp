class MedianFinder {
public:
    priority_queue<int>mxhp;
    priority_queue<int, vector<int>, greater<int>>mnhp;
    int cnt=0;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mxhp.push(num);
        cnt++;
        if(!(cnt&1)){
            mnhp.push(mxhp.top());
            mxhp.pop();
        }
        if(!mnhp.empty() && !mxhp.empty() && mnhp.top()<mxhp.top()) {
            int x = mnhp.top();
            mnhp.pop();
            int y = mxhp.top();
            mxhp.pop();
            mxhp.push(x);
            mnhp.push(y);
        }
    }
    
    double findMedian() {
        if(!(cnt&1)){
            return ((double)mxhp.top()+mnhp.top())/2;
        }
        else return (double)mxhp.top();
    }


};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
