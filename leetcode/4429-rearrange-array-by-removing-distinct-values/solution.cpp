class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int mx = *max_element(nums.begin(),nums.end());
        vector<int>freq(mx+1);

        for(auto ele:nums){
            freq[ele]++;
        }

        int n = nums.size();

        vector<int>ans;

        while(n){
            for(int i=0;i<=mx;i++){
                if(freq[i]){
                    ans.push_back(i);
                    freq[i]--;
                    n--;
                }
            }
        }

        return ans;
    }
};
