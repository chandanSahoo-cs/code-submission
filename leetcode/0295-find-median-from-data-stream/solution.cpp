class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<>>mnheap;
    priority_queue<int>mxheap;

    MedianFinder() {
    }
    
    void addNum(int num) {
        mnheap.push(num);

        mxheap.push(mnheap.top());
        mnheap.pop();

        if(mxheap.size()>mnheap.size()){
            mnheap.push(mxheap.top());
            mxheap.pop();
        }

    }
    
    double findMedian() {
        if(mnheap.size()>mxheap.size()){
            return (double)mnheap.top();
        }

        return ((double)mnheap.top()+mxheap.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
