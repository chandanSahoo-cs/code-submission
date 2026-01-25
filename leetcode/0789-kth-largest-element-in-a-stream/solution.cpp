class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int threshold;

    KthLargest(int k, vector<int>& nums) {
        threshold = k;

        for(auto ele:nums){
            pq.push(ele);
            if(pq.size()>threshold){
                pq.pop();
            }
        }    
    }
    
    int add(int val) {
        pq.push(val);

        if(pq.size()>threshold) pq.pop();

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
