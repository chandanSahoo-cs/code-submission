#define ll long long

class Solution {
public:
    ll elevatorRequests(int n, int start, vector<vector<int>>& req) {
       ll m = req.size();

        // time,curr,bits
        priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>,greater<>>pq;
        vector<vector<ll>>mark(m+1,vector<ll>(1<<m,LLONG_MAX));

        pq.push({0,0,(1<<m)-1});
        mark[0][(1<<m)-1] = 0;
        
        while(!pq.empty()){
            auto [time,curr,bits] = pq.top();
            pq.pop();

            if(bits==0) return time;

            if(mark[curr][bits]<time) continue;

            for(int i=0;i<m;i++){
                if(bits&(1<<(m-1-i))){
                    ll nbits = bits&~(1<<(m-1-i));
                    ll t = max((ll)req[i][0],time+abs(req[i][1]-(curr==0?start:req[curr-1][1])));
                    if(mark[i+1][nbits]>t){
                        mark[i+1][nbits] = t;
                        pq.push({t,i+1,nbits});
                    }
                }
            }
        }

        return -1;
    }
};
