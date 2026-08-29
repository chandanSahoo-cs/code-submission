class Solution {
public:

    int compute(vector<int>&a){
        int n = a.size();
        if(n==1) return 0;
        
        vector<int>pref(n),suff(n);
        
        pref[0] = a[0];
        for(int i=1;i<n;i++){
            pref[i] = __gcd(pref[i-1],a[i]);    
        }

        suff[n-1] = a[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = __gcd(suff[i+1],a[i]);
        }

        int cnt = 0;
        for(int i=0;i<n-1;i++){
            cnt+=(pref[i]==suff[i+1]);
        }

        return cnt;
    }
    
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        
        int mx = compute(nums);

        for(int i=0;i<n;i++){
            vector<int>a;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                a.push_back(nums[j]);
            }
            mx = max(mx,compute(a));
        }

        return mx;
    }
};
