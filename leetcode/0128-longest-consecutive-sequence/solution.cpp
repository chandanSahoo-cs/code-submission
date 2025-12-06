class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>mp(nums.begin(),nums.end());
        int ans=0;

        for(auto ele:mp){
            int len=1;
            if(mp.find(ele-1)==mp.end()){
                int tr = ele+1;
                while(mp.find(tr)!=mp.end()){
                    len++;
                    tr++;
                }
                ans=max(ans,len);
            }
        }

        return ans;
    }
};
