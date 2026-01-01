class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>ans;
        int carry=1;    
        for(int i=digits.size()-1;i>=0;i--){
            int ele = digits[i];
            ele+=carry;
            carry=0;
            if(ele>9){
                ele=0;
                carry=1;
            }
            ans.push_back(ele);
        }

        if(carry){
            ans.push_back(carry);
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
