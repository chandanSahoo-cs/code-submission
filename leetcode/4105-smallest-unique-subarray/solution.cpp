    
class Solution {
public:
    bool check(vector<int>& nums, int m){
        using ull = unsigned long long;
        int n = nums.size();
        static const ull P = 131;
        unordered_map<ull,int>mp;

        vector<ull>pref(n+1),power(n+1,1);

        for(int i=0;i<n;i++){
            pref[i+1] = pref[i]*P+nums[i]+1;
            power[i+1] = power[i]*P;
        }

        for(int i=0;i+m-1<n;i++){
            int l = i, r = i+m-1;
            ull hash = pref[r+1]-pref[l]*power[r-l+1];
            mp[hash]++;
        }

        for(auto &[key,val]:mp){
            if(val==1) return true;
        }

        return false;
    }

    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        int l = 1, r = n;
        int ans = r;

        while(l<=r){
            int m = l+(r-l)/2;

            if(check(nums,m)){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }

        return ans;
    }
};
