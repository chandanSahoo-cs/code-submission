class Solution {
public:
    string compute(int n){
        if(n==1) return "a";

        string ans = "";
        
        for(int i=25;i>=0;i--){
            int sub = 1<<i;

            int fac = n/sub;
            ans+=string(fac,'a'+i);
            n-=(fac*sub);
        }

        return ans;
    }
    
    vector<string> largestString(vector<int>& nums) {
        int n = nums.size();

        vector<string>ans;
        
        for(auto ele:nums){
            ans.push_back(compute(ele));    
        }

        return ans;
    }
};
/*
*/
