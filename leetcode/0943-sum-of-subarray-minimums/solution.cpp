class Solution {
public:
    const int mod = 1e9+7;
    vector<int> lnge(vector<int>&a){
        int n = a.size();
        vector<int>ans(n,0);

        stack<int>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>a[i]){
                st.pop();
            }
            if(!st.empty()) ans[i]=st.top()+1;
            st.push(i);
        }

        return ans;
    }

    vector<int> rnge(vector<int>&a){
        int n = a.size();
        vector<int>ans(n,n-1);
        stack<int>st;

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            if(!st.empty()) ans[i]=st.top()-1;
            st.push(i);
        }

        return ans;
    }


    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int>ln = lnge(arr);
        vector<int>rn = rnge(arr);
        long long ans = 0;
        for(int i=0;i<n;i++){
            // ans = modSum(ans,modMul(arr[i],modSum(1,modSum(i-ln[i],rn[i]-i))))
            ans=(ans+(arr[i]*1LL*(1+(i-ln[i])+(rn[i]-i)+((i-ln[i])*1LL*(rn[i]-i))%mod))%mod)%mod; 

            
        }
        return ans;
    }
};
