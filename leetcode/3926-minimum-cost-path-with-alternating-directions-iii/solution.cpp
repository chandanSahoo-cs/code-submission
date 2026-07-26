#define ll long long

class Solution {
public:
    ll minCost(int n, int m, vector<vector<int>>& penalty) {
        int dr[] = {0,0,-1,1};
        int dc[] = {-1,1,0,0};

        vector<vector<vector<ll>>>dist(n,vector<vector<ll>>(m,vector<ll>(2,LLONG_MAX)));
        // cost,i,j,p
        priority_queue<tuple<ll,ll,ll,ll>,vector<tuple<ll,ll,ll,ll>>,greater<>>pq;

        pq.push({1,0,0,0});
        dist[0][0][0] = 1;

        while(!pq.empty()){
            auto [cost,i,j,p] = pq.top();
            pq.pop();

            if(dist[i][j][p&1]<cost) continue;

            if(dist[i][j][(p+1)%2]>cost+penalty[i][j]){
                dist[i][j][(p+1)%2] = cost+penalty[i][j];
                pq.push({cost+penalty[i][j],i,j,p+1});
            }

            for(int k=0;k<4;k++){
                ll r = i+dr[k];
                ll c = j+dc[k];

                if(r<0 || r>=n || c<0 || c>=m) continue;

                bool flag = ((dc[k]==1 || dr[k]==1) && (p+1)&1) || ((dc[k]==-1 || dr[k]==-1) && !((p+1)&1));

                if(flag){
                    if(dist[r][c][(p+1)%2]>cost+(r+1)*(c+1)){
                        dist[r][c][(p+1)%2] = cost+(r+1)*(c+1);
                        pq.push({dist[r][c][(p+1)%2],r,c,p+1});
                    }
                }else{
                    if(dist[r][c][(p+1)%2]>cost+(r+1)*(c+1)+penalty[i][j]){
                        dist[r][c][(p+1)%2] = cost+(r+1)*(c+1)+penalty[i][j];
                        pq.push({dist[r][c][(p+1)%2],r,c,p+1});
                    }
                }
            }
        }

        return min(dist[n-1][m-1][0],dist[n-1][m-1][1]);
    }
};
