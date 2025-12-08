class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();

        int mx = 0;
        for(int h=-n+1;h<n;h++){
            for(int v=-n+1;v<n;v++){

                int cnt=0;

                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        int dr = i+h;
                        int dc = j+v;

                        if(dr<0 || dr>=n || dc<0 || dc>=n) continue;

                        if(img1[i][j]==img2[dr][dc] && img2[dr][dc]==1) cnt++;
                    }
                }

                mx = max(mx,cnt);
            }
        }

        return mx;
    }
};
