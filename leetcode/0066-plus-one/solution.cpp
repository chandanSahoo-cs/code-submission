class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=1;
        for(int i=digits.size()-1;i>=0||carry>0;i--){
            if(carry==0) break;
            int x=i>=0?digits[i]:0;
            int sum=x+carry;
            carry=sum/10;
            if(i>=0){
                digits[i]=sum%10;
            }
            else{
                digits.emplace(digits.begin(),sum%10);
            }
        }
        return digits;
    }
};
