class Solution {
public:
    int giveValue(int a){
        int cnt=0;

        while(a&(1<<cnt)){
            cnt++;
        }

        if(cnt==0) return -1;

        a = a&~(1<<(cnt-1));

        return a;
    }

    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();

        vector<int>ans;
        for(int i=0;i<n;i++){
            ans.push_back(giveValue(nums[i]));
        }

        return ans;
    }
};
