class Solution {
public:
    int digSum(int n){
        int sum=0;

        while(n>0){
            sum+=n%10;
            n/=10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,pair<int,int>>mp;

        for(int i=0;i<n;i++){
            int dig= digSum(nums[i]);
            if(mp.find(dig)==mp.end()){
                mp[dig]={-1,nums[i]};
            }else{
                if(nums[i]>=mp[dig].second){
                    mp[dig].first=mp[dig].second;
                    mp[dig].second=nums[i];
                }else if(nums[i]>=mp[dig].first){
                    mp[dig].first=nums[i];
                }
            }
        }

        int mx=-1;

        for(auto [key,value]:mp){
            if(value.first==-1) continue;
            mx = max(mx,value.first+value.second);
        }

        return mx;
    }


};
