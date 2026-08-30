#define ll long long
class Solution {
public:
    ll dp[105][5005];
    bool mark[105][5005];

    ll rec(vector<int>& nums, int i, ll sum, ll tr){
        int n = nums.size();

        if(sum==tr) return 0;

        if(i==n || sum>tr) return -1;

        if(mark[i][sum]) return dp[i][sum];

        int mn = rec(nums,i+1,sum,tr);

        for(int j = 0;j<30;j++){
            if(((1LL*nums[i])<<j)>tr) break;
            int p = rec(nums,i+1,sum+((1LL*nums[i])<<j),tr);
            if(p!=-1){
                if(mn==-1) mn = j+p;
                else mn = min(mn,j+p);
            }
        }

        for(int j = 0;j<30;j++){
            if(((1LL*nums[i])>>j)==0) break;
            int p = rec(nums,i+1,sum+((1LL*nums[i])>>j),tr);
            if(p!=-1){
                if(mn==-1) mn = j+p;
                else mn = min(mn,j+p);
            }
        }

        mark[i][sum]=true;
        return dp[i][sum] = mn;
    }

    int minOperations(vector<int>& nums, int sum) {
        int n = nums.size();

        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                mark[i][j]=false;
            }
        }


        return rec(nums,0,0,sum);
    }
};
