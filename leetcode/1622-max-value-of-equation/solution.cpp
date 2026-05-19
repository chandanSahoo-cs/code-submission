class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& pts, int k) {
        int n = pts.size();

        priority_queue<pair<int,int>>pq;
        pq.push({pts[n-1][0]+pts[n-1][1],pts[n-1][0]});

        int mx = INT_MIN;

        for(int i=n-2;i>=0;i--){
            while(!pq.empty() && pq.top().second-pts[i][0]>k) pq.pop();
            int sum = pts[i][0]+pts[i][1];
            int diff = pts[i][1]-pts[i][0];

            if(!pq.empty()){
                mx = max(mx,pq.top().first+diff);
            }
            pq.push({sum,pts[i][0]});    
        }

        return mx;
    }
};

/*
yi+yj+|xi-xj| where i<j
=> yi+yj+xj-xi
=>yi-xi+yj+xj
*/
