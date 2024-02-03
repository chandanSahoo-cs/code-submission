class Solution {
    #define ll long long
    #define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
public:
    string triangleType(vector<int>& nums) {
        fastio
        bool flag=true;
        if(nums[0]+nums[1]<=nums[2]) flag=false;
        if(nums[0]+nums[2]<=nums[1]) flag=false;
        if(nums[1]+nums[2]<=nums[0]) flag =false;
        if(flag){
            if(nums[0]==nums[1] && nums[1]==nums[2]) return "equilateral";
            else if((nums[0]==nums[1] && nums[1]!=nums[2]) || (nums[1]==nums[2] && nums[2]!=nums[0]) || (nums[2]==nums[0] && nums[0]!=nums[1])) return "isosceles";
            else return "scalene";
        }
        else return "none";
    }
}; 
