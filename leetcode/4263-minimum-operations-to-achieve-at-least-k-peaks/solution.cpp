const int INF = 1e9;
class Solution {
public:

    // int rec(vector<int>&nums, int i, int k,int c){
    //     int n = nums.size();

    //     if(k==0) return 0;
        
    //     if(c==0 && i>=n-1) return INF;
    //     if(c==1 && i>=n) return INF;

    //     if(dp[i][k][c]!=-1) return dp[i][k][c];

    //     int left = 0, right= 0 ;

    //     if(i>0){
    //         left = nums[i-1]-nums[i]+1;
    //     }else{
    //         left = nums[n-1]-nums[i]+1;
    //     }
        
    //     if(i<n-1){
    //         right = nums[i+1]-nums[i]+1;
    //     }else{
    //         right = nums[0]-nums[i]+1;
    //     }

    //     int need = max(0,max(left,right));

    //     int p = need+rec(nums,i+2,k-1,c);
    //     int np = rec(nums,i+1,k,c);

    //     if(min(p,np)>=INF) return dp[i][k][c]=INF;

    //     return dp[i][k][c]=min(p,np);
    // }
    
    int minOperations(vector<int>& nums, int k) {

        int n = nums.size();

        vector<vector<int>>dp0(n+2,vector<int>(k+1));
        vector<vector<int>>dp1(n+2,vector<int>(k+1));

        for(int j=1;j<=k;j++){
            dp0[n-1][j]=INF;
            dp0[n][j]=INF;
            dp0[n+1][j]=INF;
        }

        for(int j=1;j<=k;j++){
            dp1[n][j]=INF;
            dp1[n+1][j]=INF;
        }

        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=k;j++){
                int left = 0, right = 0 ;

                if(i>0){
                    left = nums[i-1]-nums[i]+1;
                }else{
                    left = nums[n-1]-nums[i]+1;
                }
                
                if(i<n-1){
                    right = nums[i+1]-nums[i]+1;
                }else{
                    right = nums[0]-nums[i]+1;
                }

                int need = max(0,max(left,right));

                int p = need+dp0[i+2][j-1];
                int np = dp0[i+1][j];

                if(min(p,np)>=INF) dp0[i][j]=INF;
                else dp0[i][j]=min(p,np);
            }
        }

        for(int i=n-1;i>=1;i--){
            for(int j=1;j<=k;j++){
                int left = 0, right = 0 ;

                if(i>0){
                    left = nums[i-1]-nums[i]+1;
                }else{
                    left = nums[n-1]-nums[i]+1;
                }
                
                if(i<n-1){
                    right = nums[i+1]-nums[i]+1;
                }else{
                    right = nums[0]-nums[i]+1;
                }

                int need = max(0,max(left,right));

                int p = need+dp1[i+2][j-1];
                int np = dp1[i+1][j];

                if(min(p,np)>=INF) dp1[i][j]=INF;
                else dp1[i][j]=min(p,np);
            }
        }

        if(min(dp0[0][k],dp1[1][k])>=INF) return -1;
        return min(dp0[0][k],dp1[1][k]);
    }
};
