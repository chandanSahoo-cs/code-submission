class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>nums;

        int fact=1;

        for(int i=1;i<n;i++){
            fact*=i;
            nums.push_back(i);
        }

        nums.push_back(n);

        string ans="";
        k--;

        while(nums.size()>0){
            ans.push_back(nums[k/fact]+'0');
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0) break;
            k%=fact;
            fact/=nums.size();
        }

        return ans;
    }
};
