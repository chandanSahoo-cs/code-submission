class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int val1=-1, val2=-1;

        for(auto ele:nums){
            if(ele>=val1){
                val2 = val1;
                val1 = ele;
            }else if(ele>val2){
                val2 = ele;
            }
        }

        return (val1-1)*(val2-1);
    }
};
