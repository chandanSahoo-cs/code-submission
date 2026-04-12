class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int,int>mp;
        mp[0]=-1;
        int cnt = 0;
        int mx = cnt;

        for(int i=0;i<n;i++){
            cnt+=(nums[i]==0?-1:1);

            if(mp.count(cnt)){
                mx = max(mx,i-mp[cnt]);
            }else mp[cnt]=i;
        }

        return mx;
    }
};
