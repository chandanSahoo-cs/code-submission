class Solution {
    #define ll long long
public:
    int maxFrequency(vector<int>& nums, int k) {
        ll n=nums.size();
        sort(nums.begin(),nums.end());
        vector<ll>prefix(n);
        prefix[n-1]=nums[n-1];
        for(ll i=n-2;i>=0;i--){
            prefix[i]+=nums[i]+prefix[i+1];
        }
        ll cons=n-1,var=n-2;
        ll cnt=1,ans=1;
        ll prev=0;
        while(cons>0 && var>=0){
            if((cons-var+1)*nums[cons]-(prefix[var]-prev)<=k){
                cnt++;
                ans=max(ans,cnt);
                var--;
            }
            else{
                prev=prefix[cons];
                cons--;
                cnt--;
            }
        }
        return ans;
    }
};
