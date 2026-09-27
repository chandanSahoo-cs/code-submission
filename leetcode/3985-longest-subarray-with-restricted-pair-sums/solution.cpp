class Solution {
public:
    int maxSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        vector<int>freq(501);

        auto check = [&](int a)->bool{

            for(int i=1;i<=500;i++){
                if(!freq[i]) continue;
                /*
                a+b = x;
                a=x-b;
                */

                if(a-i>=0 && a-i<=500){
                    if(a-i==i && freq[a-i]>1) return false;
                    if(a-i!=i && freq[a-i]>0) return false;
                }

                if(i+a<=500 && freq[i+a]) return false;
            }
            return true;
        };

        int ans = 0;

        while(r<n){

            while(l<=r && !check(nums[r])){
                freq[nums[l]]--;
                l++;
            }
            
            freq[nums[r]]++;
            ans = max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};

/*
a+b=c
a+c=b
b+c=a
*/
