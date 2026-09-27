class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        int n = nums.size();

        map<pair<int,int>,int>mp;
        int total = 0;

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                total++;
            }else{
                int a = nums[i], b = nums[i-1];
                if(a>b) swap(a,b);
                mp[{a,b}]++;
            }
        }

        int ans = total;

        for(auto &[key,val]:mp){
            ans = max(ans,total+val);
        }

        return ans;
    }
};

/*
2 8 2 5 5 6
2 2 2 5 5 6
2 8 2 2 2 6
2 8 2 5 5 5
5 8 5 5 5 6
*/
