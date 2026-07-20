class Zone{
public :
    int walls = 0;
    set<pair<int,int>>poss;
    vector<pair<int,int>>bound;

    Zone(int w, set<pair<int,int>>&pos, vector<pair<int,int>>&b) : walls(w), poss(pos), bound(b){};
};

struct Compare {
    bool operator()(const Zone& z1, const Zone& z2) const {
        return z1.poss.size() < z2.poss.size();
    }
};

class Solution {
public:

    void fill(priority_queue<Zone,vector<Zone>,Compare> &pq, vector<vector<int>>& infect){
        int n = infect.size(), m = infect[0].size();
        

        vector<vector<int>>vis(n,vector<int>(m));
        queue<pair<int,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(infect[i][j]!=1 || vis[i][j]) continue;

                q.push({i,j});
                vis[i][j]=1;

                set<pair<int,int>>st;
                vector<pair<int,int>>bound;
                int walls=0;

                int dr[] = {0,0,-1,1};
                int dc[] = {-1,1,0,0};

                while(!q.empty()){
                    auto [r,c] = q.front();
                    bound.push_back({r,c});
                    q.pop();

                    for(int k=0;k<4;k++){
                        int nr = r+dr[k];
                        int nc = c+dc[k];

                        if(nr<0 || nr>=n || nc<0 || nc>=m || vis[nr][nc]) continue;

                        if(infect[nr][nc]==1){
                            q.push({nr,nc});
                            vis[nr][nc]=1;
                        }else if (infect[nr][nc]==0){
                            walls++;
                            st.insert({nr,nc});
                        } 
                    }
                }

                pq.push(Zone(walls,st,bound));
            }
        }

    }

    int containVirus(vector<vector<int>>& infect) {
        int n = infect.size(), m = infect[0].size();

        int ans = 0;

        priority_queue<Zone,vector<Zone>,Compare>pq;
        fill(pq,infect);

        while(!pq.empty()){
            ans+=pq.top().walls;

            for(auto &[r,c]:pq.top().bound){
                infect[r][c]=-1;
            }
            pq.pop();

            if(!pq.empty()){

                while(!pq.empty()){
                    Zone z = pq.top();
                    pq.pop();

                    for(auto &[r,c]:z.poss){
                        if(infect[r][c]) continue;
                        infect[r][c]=1;
                    }
                }

                fill(pq,infect);
            }
        }

        return ans;
    }
};
