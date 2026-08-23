class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>freq(*max_element(nums.begin(),nums.end())+1);
        int cnt = 0;

        auto add = [&](int val){
            int tval = val;
            for(int i = 2;i*i<=tval;i++){
                int acc = 0;
                while(tval%i==0){
                    tval/=i;
                    acc++;
                }
                
                if(acc!=0 && freq[i]==0) cnt++;
                freq[i]+=acc;
            }

            if(tval>1){
                if(freq[tval]==0) cnt++;
                freq[tval]++;
            }
        };

        auto sub = [&](int val){
            int tval = val;
            for(int i = 2;i*i<=tval;i++){
                int acc = 0;
                while(tval%i==0){
                    tval/=i;
                    acc++;
                }
                
                freq[i]-=acc;

                if(acc!=0 && freq[i]==0) cnt--;
            }

            if(tval>1){
                freq[tval]--;
                if(freq[tval]==0) cnt--;
            }
        };

        int l = 0, r = 0;
        int mx = 0;

        while(r<n){
            add(nums[r]);

            while(l<=r && cnt>k){
                sub(nums[l]);
                l++;
            }

            mx = max(mx,r-l+1);
            r++;
        }

        return mx;
    }
};
