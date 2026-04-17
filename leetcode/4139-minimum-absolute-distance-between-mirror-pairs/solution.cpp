class Solution {
public:
    int rev(int x){
        int y = 0;

        while(x){
            y*=10;
            y+=(x%10);
            x/=10;
        }

        return y; 
    }

    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        int ans = INT_MAX;

        for(int i=0;i<n;i++){
            int x = nums[i];
            int y = rev(nums[i]);
            if(mp.count(x)){
                ans = min(ans,abs(i-mp[x]));
            }
            mp[y]=i;
        }

        return ans==INT_MAX?-1:ans;    
    }
};
