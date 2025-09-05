class Solution {
public:
    int state[100];
    int dp(int n, int level){
        if(level>n) return 0;

        if(level==n) return 1;
        int ans=0;
        if(state[level]!=-1) return state[level];
        for(int i=1;i<=2;i++){
            if(level+i<=n){
                ans+=dp(n,level+i);
            }
        }

        return state[level]=ans;
    }

    int climbStairs(int n) {
        memset(state,-1,sizeof(state));
        return dp(n,0);    
    }
};
