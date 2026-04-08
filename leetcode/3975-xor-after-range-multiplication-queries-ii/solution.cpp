const int mod = 1e9+7;
class Solution {
public:

    int binExp(int a, int b){
        int ans = 1;

        while(b){
            if(b&1){
                ans = (a*1LL*ans)%mod;
            }
            a = (a*1LL*a)%mod;
            b>>=1;
        }

        return ans;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        int b = sqrt(n);

        vector<vector<int>>prefMul(b+1,vector<int>(n,1));
        unordered_set<int>st;

        for(auto &ele:queries){
            int l = ele[0], r = ele[1], k = ele[2], v = ele[3];

            if(k<=b){
                st.insert(k);
                int step = (r-l)/k;
                int x = l+(step+1)*k;
                prefMul[k][l] = (prefMul[k][l]*1LL*v)%mod;
                if(x<n){
                    prefMul[k][x] = (prefMul[k][x]*1LL*binExp(v,mod-2))%mod;
                }
            }else{
                for(int i = l;i<=r;i+=k){
                    nums[i] = (nums[i]*1LL*v)%mod;
                }
            }
        }

        for(int i=1;i<=b;i++){
            if(!st.count(i)) continue;
            for(int j=0;j<n;j++){
                if(j-i>=0){
                    prefMul[i][j] = (prefMul[i][j]*1LL*prefMul[i][j-i])%mod;
                }
                nums[j] = (nums[j]*1LL*prefMul[i][j])%mod;
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++){
            ans^=nums[i];
        }

        return ans;
    }
};
