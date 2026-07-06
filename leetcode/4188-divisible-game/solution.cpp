const int mod = 1e9+7;

class Solution {
public:
    void compute(int n,unordered_set<int>&divs){
        
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                divs.insert(i);
                divs.insert(n/i);
            }
        }
        divs.insert(n);
    }

    int divisibleGame(vector<int>& nums) {
        
        unordered_set<int>divs;

        for(auto ele:nums){
            if(ele==1) continue;
            compute(ele,divs);
        }

        int mxSum = -(*min_element(nums.begin(),nums.end()));
        int k = 2;


        for(auto d:divs){
            int sum = 0;
            for(auto ele:nums){
                int val = ele;
                if(ele%d!=0) val=-val;
                sum = max(sum+val,val);

                if(sum>mxSum){
                    mxSum = sum;
                    k = d;
                }else if(sum==mxSum){
                    k = min(k,d);
                }
            }
        }

        return ((mxSum*1LL*k)+mod)%mod;
    }
};
