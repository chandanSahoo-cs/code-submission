class Solution {
public:
    int minMoves(vector<string>& cr, int energy) {
        int n = cr.size();
        int m = cr[0].size();

        /*
        states : n,m,energy,litter
        value : steps;
        */

        int sr, sc;
        int litter = 0;

        vector<vector<int>>store(n,vector<int>(m));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(cr[i][j]=='L'){
                    store[i][j] = 1<<litter;
                    litter++;
                }
                if(cr[i][j]=='S'){
                    sr=i,sc=j;
                }
            }
        }

        
        vector<vector<vector<vector<char>>>>mark(n,vector<vector<vector<char>>>(m,vector<vector<char>>(energy+1,vector<char>(1<<litter))));
        queue<tuple<int,int,int,int,int>>q;

        /*
        20*20*50
        20000*400
        8000000
        */

        q.push({sr,sc,energy,0,0});
        mark[sr][sc][energy][0] = 1;

        int dr[] = {0,0,-1,1};
        int dc[] = {1,-1,0,0};

        while(!q.empty()){
            auto [r,c,e,l,mv] = q.front();
            q.pop();

            if(l==(1<<litter)-1) return mv;
            if(cr[r][c]=='R') e=energy;

            for(int k=0;k<4;k++){
                int nr = r+dr[k];
                int nc = c+dc[k];

                if(nr<0 || nr>=n || nc<0 || nc>=m || e-1<0 || cr[nr][nc]=='X') continue;

                int currL = l;


                if(cr[nr][nc]=='L' && (currL&store[nr][nc])==0){
                    currL|=store[nr][nc];
                }

                if(mark[nr][nc][e-1][currL]) continue;

                mark[nr][nc][e-1][currL] = 1;
                q.push({nr,nc,e-1,currL,mv+1});
            }
        }

        return -1;
    }
};
