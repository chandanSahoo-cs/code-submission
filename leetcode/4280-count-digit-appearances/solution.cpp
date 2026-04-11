class Solution {
public:
    void calc(vector<int>&cnt, int ele){
        while(ele){
            cnt[ele%10]++;
            ele/=10;
        }

        return;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        vector<int>cnt(10);

        for(auto ele:nums){
            calc(cnt,ele);
        }

        return cnt[digit];
    }
};
