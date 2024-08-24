class Solution {
    #define ll long long
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        ll cnt=0;
        for(ll i=1;i<=n;i++){
            if(nums[i%(n)]<nums[(i-1)%(n)]){
                cnt++;
            }
            if(cnt==2) break;
        }
        if(cnt<2) return 1;
        else return 0;
    }
};
