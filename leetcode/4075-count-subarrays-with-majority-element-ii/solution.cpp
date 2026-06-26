#define ll long long

class Solution {
public:
    ll countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();

        unordered_map<int,int>mp;
        ll cnt = 0;
        ll valid = 0;
        int sum = 0; 

        mp[sum] = 1;

        /*
        we just need to cnt how many prev pref sum are less then curr pref sum
        and as pref sum only changes by (+1/-1) we can easily keep track of how many prev pref sum is smaller then curr pref sum 
        */

        for(int i=0;i<n;i++){
            int val = (nums[i]==target)?1:-1;

            if(val==1){
                valid+=mp[sum];
            }else valid-=mp[sum+val];
                                                                                                                      
            sum+=val;
            mp[sum]+=1;
            cnt+=valid;

        }

        return cnt;
    }
};
