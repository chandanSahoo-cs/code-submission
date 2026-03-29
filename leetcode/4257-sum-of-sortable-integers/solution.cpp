class Solution {
public:

    bool validate(vector<int>&nums, int k){
        int n = nums.size();

        int i = 0;
        int mx = -1;

        while(i<n){
            int currMx = -1;
            int currMn = INT_MAX;

            int cnt = 0;
            
            for(int j=0;j<k;j++){
                // if(j==k-1){
                //     if(nums[i+j]>nums[i]) cnt++;
                // }else{
                //     if(nums[i+j]>nums[i+j+1]) cnt++;
                // }
                if(nums[i+j]>nums[i+(j+1)%k]) cnt++;
                currMx = max(nums[i+j],currMx);
                currMn = min(nums[i+j],currMn);
            }

            if(cnt>1) return false;

            if(mx>currMn) return false;
            mx = currMx;
            
            i+=k;
        }

        return true;
    }
    
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int>divs;
        
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                divs.push_back(i);
                if(i!=n/i) divs.push_back(n/i);
            }
        }


        int sum = 0;

        for(auto ele:divs){
            if(validate(nums,ele)){
                sum+=ele;
            }
        }

        return sum;
    }
};
