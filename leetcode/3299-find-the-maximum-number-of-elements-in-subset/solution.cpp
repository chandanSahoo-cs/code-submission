#define ll long long

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mp;
        
        for(auto ele:nums){
            mp[ele]++;
        }

        int mx = 0;

        for(int i=0;i<n;i++){
            int cnt = 0;

            ll ele = nums[i];

            if(ele==1){
                if(mp.count(1)){
                    int freq = mp[1];
                    mx = max(mx,freq&1?freq:freq-1);
                }
                continue;
            }

            while(true){
                if(mp.count(ele)){
                    if(mp[ele]==1){
                        cnt++;
                        break;
                    }else{
                        cnt+=2;
                    }
                }else{
                    cnt--;
                    break;
                }
                
                if(ele*ele>1e9){
                    cnt--;
                    break;
                }
                ele*=ele;
            }

            mx = max(mx,cnt);
        }

        return mx;
    }
};
