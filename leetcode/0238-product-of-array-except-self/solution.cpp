class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // vector<int>answer(nums.size());
        // for(int k=0;k<nums.size();k++){
        //     int i=0;
        //     int product=1;
        //     while(i<k){
        //         product*=nums[i++];
        //     }
        //     answer[k]=product;
        // }
        // for(int k=0;k<nums.size();k++){
        //     int j=nums.size()-1;
        //     int product=1;
        //     while(j>k){
        //         product*=nums[j--];
        //     }
        //     answer[k]*=product;
        // }
        // return answer;
        vector<int>answer(nums.size(),1);
        int leftProduct=1;
        for(int i=0;i<nums.size();i++){
            answer[i]*=leftProduct;
            leftProduct*=nums[i];
        }

        int rightProduct=1;
        for(int i=nums.size()-1;i>=0;i--){
            answer[i]*=rightProduct;
            rightProduct*=nums[i];
        }
        return answer;
    }
};
