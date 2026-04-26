class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++){
            if(i==0 || i==n-1) ans.push_back(nums[i]);
            else{
                bool flag = true;
                for(int j=0;j<i;j++){
                    if(nums[i]<=nums[j]){
                        flag=false;
                        break;
                    }
                }

                if(flag){
                    ans.push_back(nums[i]);
                }else{
                    flag = true;
                    for(int j=n-1;j>i;j--){
                        if(nums[i]<=nums[j]){
                            flag=false;
                            break;
                        }
                    }

                    if(flag){
                        ans.push_back(nums[i]);
                    }
                }
            }
        }

        return ans;
    }
};
