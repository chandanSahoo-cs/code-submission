const int mod = 1e9+7;
class Solution {
public:
    int binExp(int a,int b){
        int ans = 1;

        while(b){
            if(b&1){
                ans = (ans*1LL*a)%mod;
            }
            a = (a*1LL*a)%mod;

            b>>=1;
        }

        return ans;
    }
    
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n = nums1.size();

        vector<int>store;
        vector<int>foo;
        
        for(int i=0;i<n;i++){
            if(nums0[i]==0) store.push_back(i);
            else foo.push_back(i);
        }

        sort(foo.begin(),foo.end(),[&](int i,int j){
            if(nums1[i]==nums1[j]) return nums0[i]<nums0[j];
            return nums1[i]>nums1[j]; 
        });

        for(auto ele:foo){
            store.push_back(ele);
        }

        int ans = 0;

        for(auto ele:store){
            int f1 = binExp(2,nums1[ele]);
            int f2 = binExp(2,nums0[ele]);
            
            ans = ((ans*1LL*f1)%mod+f1-1)%mod;
            ans = (ans*1LL*f2)%mod;
        }
        
        return ans;
    }
};
