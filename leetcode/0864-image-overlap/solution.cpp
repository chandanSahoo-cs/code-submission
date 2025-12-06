class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int mx=0;
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){

                int cnt=0;
                for(int r=0;r<n;r++){
                    for(int c=0;c<n;c++){

                        int y=r+i;
                        int x=c+j;

                        if(x<0 || x>=n || y<0 || y>=n) continue;
                        cnt+=(img1[r][c]==img2[y][x] && img2[y][x]==1);
                    
                    }
                }

                mx = max(cnt,mx);
            }
        }

        return mx;
    }
};
