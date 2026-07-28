class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int mx = 0;

        for(auto &ele:nums){
            mx = max(abs(ele),mx);
        }

        vector<int>freq(mx+1);

        for(auto ele:nums){
            freq[abs(ele)]++;
        }

        vector<int>ans;

        for(int i=0;i<=mx;i++){
            
            while(freq[i]>0){
                ans.push_back(i*i);
                freq[i]--;
            }
        }

        return ans;
    }
};
