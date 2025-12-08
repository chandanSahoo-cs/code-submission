class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>mp;

        for(auto ele1:nums1){
            for(auto ele2:nums2){
                mp[ele1+ele2]++;
            }
        }

        int cnt=0;

        for(auto ele3:nums3){
            for(auto ele4:nums4){
                if(mp.find(-ele3-ele4)!=mp.end()){
                    cnt+=mp[-ele3-ele4];
                }
            }
        }

        return cnt;
    }
};
