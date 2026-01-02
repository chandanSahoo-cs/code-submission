class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        vector<int>freq(1e4+1,0);

        for(auto ele:nums) freq[ele]++;
        auto mxPtr = max_element(freq.begin(),freq.end());
        auto indPtr = mxPtr-freq.begin();
        return indPtr;
    }
};
