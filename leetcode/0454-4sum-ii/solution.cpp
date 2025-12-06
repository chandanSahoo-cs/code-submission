class Solution {
public:
    void mark(vector<int>&nums1, vector<int>&nums2, unordered_map<int,int>&fst){
        int n=nums1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int tr = nums1[i]+nums2[j];
                if(fst.find(tr)==fst.end()){
                    fst[tr]=1;
                }else fst[tr]++;
            }
        }
    }

    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>scnd;
        mark(nums3,nums4,scnd);

        int cnt=0;
        int n=nums1.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int tr = nums1[i]+nums2[j];
                if(scnd.find(-tr)!=scnd.end()){
                    cnt+=scnd[-tr];
                }
            }
        }

        return cnt;
    }
};
