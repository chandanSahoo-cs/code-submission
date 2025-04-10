class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>a(26,0);

        for(auto ele:tasks){
            a[ele-'A']++;
        }

        priority_queue<int>pq;

        for(auto ele:a){
            if(ele!=0) pq.push(ele);
        }
        queue<int>q;
        int ans=0;


        int mx=-1;
        while(!pq.empty()){
            q.push(pq.top()-1);
            mx = max(mx,pq.top()-1);
            pq.pop();
            if(q.size()==n+1 || pq.empty()){
                if(mx==0){
                    ans+=q.size();
                }
                else{
                    ans+=n+1;
                }
                while(!q.empty()){
                    if(q.front()!=0){
                        pq.push(q.front());
                    }
                    q.pop();
                }
                mx=-1;
            }
        }

        return ans;


    }
};
