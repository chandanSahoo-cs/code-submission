class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind=-1;

        for(int i=0;i<n-1;i++){
            if(nums[i]<nums[i+1]){
                ind=i;
            }
        }

        if(ind==-1){
            sort(nums.begin(),nums.end());
        }else{
            for(int i=0;i<n;i++){
                if(i==ind){
                    int val=nums[ind+1];
                    int k=ind+1;

                    for(int l=ind+1;l<n;l++){
                        if(val>nums[l] && nums[l]>nums[ind]){
                            val=nums[l];
                            k=l;
                        }
                    }

                    swap(nums[i],nums[k]);
                    sort(nums.begin()+i+1,nums.end());
                    break;
                }
            }
        }
    }
};
