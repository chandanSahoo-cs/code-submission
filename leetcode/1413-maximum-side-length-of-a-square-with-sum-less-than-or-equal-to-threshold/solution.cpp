class Solution {
public:
    bool check(int n,int m, vector<vector<int>>&pref, int side, int threshold){
        for(int i=1;i+side<=n;i++){
            for(int j=1;j+side<=m;j++){
                if(pref[i+side][j+side]-pref[i-1][j+side]-pref[i+side][j-1]+pref[i-1][j-1]<=threshold){
                    return true;
                }
            }
        }

        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>pref(n+1,vector<int>(m+1));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                pref[i+1][j+1]+=pref[i+1][j]+pref[i][j+1]+mat[i][j]-pref[i][j];
            }
        }

        int mx = 0;
        int l=0,r=min(n,m);

        while(l<=r){
            int side = l+(r-l)/2;
            bool flag=false;
            if(check(n,m,pref,side,threshold)){
                mx = max(mx,side+1);
                l=side+1;
            }else r=side-1;
        }

        return mx;
    }
};
