#define ll long long
const int mod = 1e9+7;

class Solution {
public:
    ll giveSm(vector<ll>&pref,int l, int r){
        ll rem = l==0?0:pref[l-1];
        return pref[r]-rem;
    }

    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();

        stack<int>st;
        vector<int>next(n,n-1),prev(n,0);

        for(int i=0;i<n;i++){

            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }

            if(!st.empty()) prev[i]=st.top()+1;
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && nums[st.top()]>=nums[i]){
                st.pop();
            }

            if(!st.empty()) next[i]=st.top()-1;

            st.push(i);
        }

        vector<ll>pref(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }

        ll mx = 0;

        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]*giveSm(pref,prev[i],next[i]));
        }

        return mx%mod;
    }
};
