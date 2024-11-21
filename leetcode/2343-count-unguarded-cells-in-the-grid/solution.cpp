class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int g = guards.size();
        int w = walls.size();
        vector<vector<int>>t(m,vector<int>(n));

        for(int i=0;i<g;i++){
            t[guards[i][0]][guards[i][1]] = 2;
        }
        for(int i=0;i<w;i++){
            t[walls[i][0]][walls[i][1]] = 3;
        }
        for(int i=0;i<=m-1;i++){
            bool flag=false;
            for(int j=0;j<=n-1;j++){
                if(t[i][j]==2){
                    flag=true;
                    if(i!=0 && !t[i-1][j]){
                        t[i-1][j]=1;
                    }
                    if(j!=0 && !t[i][j-1]){
                        t[i][j-1]=1;
                    }
                    if(i!=m-1 && !t[i+1][j]){
                        t[i+1][j]=1;
                    }
                    if(j!=n-1 && !t[i][j+1]){
                        t[i][j+1]=1;
                    }
                }
                else if(t[i][j]==3){
                    flag=false;
                }
                else if(flag){
                    t[i][j]=1;
                }
            }
        }

        for(int i=m-1;i>=0;i--){
            bool flag=false;
            for(int j=n-1;j>=0;j--){
                if(t[i][j]==2){
                    flag=true;
                    if(i!=0 && !t[i-1][j]){
                        t[i-1][j]=1;
                    }
                    if(j!=0 && !t[i][j-1]){
                        t[i][j-1]=1;
                    }
                    if(i!=m-1 && !t[i+1][j]){
                        t[i+1][j]=1;
                    }
                    if(j!=n-1 && !t[i][j+1]){
                        t[i][j+1]=1;
                    }
                }
                else if(t[i][j]==3){
                    flag=false;
                }
                else if(flag){
                    t[i][j]=1;
                }
            }
        }

        for(int j=0;j<=n-1;j++){
            bool flag=false;
            for(int i=0;i<=m-1;i++){
                if(t[i][j]==2){
                    flag=true;
                    if(i!=0 && !t[i-1][j]){
                        t[i-1][j]=1;
                    }
                    if(j!=0 && !t[i][j-1]){
                        t[i][j-1]=1;
                    }
                    if(i!=m-1 && !t[i+1][j]){
                        t[i+1][j]=1;
                    }
                    if(j!=n-1 && !t[i][j+1]){
                        t[i][j+1]=1;
                    }
                }
                else if(t[i][j]==3){
                    flag=false;
                }
                else if(flag){
                    t[i][j]=1;
                }
            }
        }

        for(int j=n-1;j>=0;j--){
            bool flag=false;
            for(int i=m-1;i>=0;i--){
                if(t[i][j]==2){
                    flag=true;
                    if(i!=0 && !t[i-1][j]){
                        t[i-1][j]=1;
                    }
                    if(j!=0 && !t[i][j-1]){
                        t[i][j-1]=1;
                    }
                    if(i!=m-1 && !t[i+1][j]){
                        t[i+1][j]=1;
                    }
                    if(j!=n-1 && !t[i][j+1]){
                        t[i][j+1]=1;
                    }
                }
                else if(t[i][j]==3){
                    flag=false;
                }
                else if(flag){
                    t[i][j]=1;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(t[i][j]) cnt++;
            }
        }
        return n*m-cnt;
    }
};
