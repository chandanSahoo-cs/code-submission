#define ll long long

class Solution {
public:
    int factor(int n, set<int>&st){

        int mn = 1e5+7;

        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(st.count(i)){
                    mn = min(mn,i);
                }

                if(st.count(n/i)){
                    mn = min(mn,n/i);
                }
            }
        }


        return mn;
    }
    
    ll minArraySum(vector<int>& nums) {
        int n = nums.size();
        set<int>st(nums.begin(),nums.end());

        ll sum = 0;
        
        for(int i=0;i<n;i++){
            sum+=factor(nums[i],st);
        }

        return sum;
    }
};
