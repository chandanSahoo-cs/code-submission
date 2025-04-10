class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        priority_queue<int,vector<int>,greater<int>>pq;

        for(auto ele:hand) pq.push(ele);

        queue<int>q;
        vector<int>cmp;

        while(!pq.empty()){
            if(cmp.size()>0 && cmp.back()==pq.top()){
                q.push(pq.top());
                pq.pop();
            }
            else if(cmp.size()==0 || cmp.back()+1==pq.top()){
                cmp.push_back(pq.top());
                pq.pop();
            }
            else{
                return 0;
            }

            if(cmp.size()==groupSize){
                cmp={};
                while(!q.empty()){
                    pq.push(q.front());
                    q.pop();
                }
            }
        }

        if(cmp.size()==0){
            return 1;
        }
        else return 0;
    }
};
