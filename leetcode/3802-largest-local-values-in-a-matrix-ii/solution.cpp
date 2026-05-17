class Solution {
public:
    vector<vector<vector<int>>>pref;

    int compute(int x, int t, int d, int l, int r){
        return pref[x][d][r]-pref[x][d][l-1]-pref[x][t-1][r]+pref[x][t-1][l-1];
    }

    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        int mx = 0;

        for(auto &row:matrix){
            mx = max(mx,*max_element(row.begin(),row.end()));
        }
        
        pref.assign(mx+1,vector<vector<int>>(n+1,vector<int>(m+1,0)));

        for(int v=0;v<mx+1;v++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    pref[v][i+1][j+1] = pref[v][i+1][j]+pref[v][i][j+1]-pref[v][i][j]+(matrix[i][j]>v);
                }
            }
        }

        int cnt = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int v = matrix[i][j];

                if(v==0) continue;

                int t = i-v, d = i+v;
                int l = j-v, r = j+v;

                int greatCnt = compute(v,max(1,t+1),min(n,d+1),max(1,l+1),min(m,r+1));

                vector<pair<int,int>>off ={{t,l},{t,r},{d,l},{d,r}};

                for(auto &[x,y]:off){
                    if(x<0 || x>=n || y<0 || y>=m) continue;
                    if(matrix[x][y]>v) greatCnt--;
                }

                if(!greatCnt){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};


