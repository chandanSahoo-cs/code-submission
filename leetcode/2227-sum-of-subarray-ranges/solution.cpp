#define ll long long
class Solution {
public:

    vector<ll>lns(vector<int>&a,ll n){
        vector<ll>ans(n,0);
        stack<ll>st;

        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top()+1;
            st.push(i);
        }
        return ans;
    }

    vector<ll>rns(vector<int>&a, ll n){
        vector<ll>ans(n,n-1);
        stack<ll>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>a[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top()-1;
            st.push(i);
        }
        return ans;
    }

    vector<ll>lnl(vector<int>&a, ll n){
        vector<ll>ans(n,0);
        stack<ll>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]<a[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top()+1;
            st.push(i);
        }
        return ans;
    }

    vector<ll>rnl(vector<int>&a,ll n){
        vector<ll>ans(n,n-1);
        stack<ll>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]<=a[i]){
                st.pop();
            }
            if(!st.empty()) ans[i] = st.top()-1;
            st.push(i);
        }
        return ans;
    }

    ll val(vector<int>&arr, vector<ll>&a, vector<ll>&b, vector<ll>&c, vector<ll>&d, ll n){
        ll mn=0,mx=0;
        for(int i=0;i<n;i++){
            mn += arr[i]*(i-a[i]+b[i]-i+1+(i-a[i])*(b[i]-i));
            mx += arr[i]*(i-c[i]+d[i]-i+1+(i-c[i])*(d[i]-i));
        }

        return mx-mn;
    }

    long long subArrayRanges(vector<int>& nums) {
        ll n = nums.size();
        vector<ll>a = lns(nums,n),b = rns(nums,n), c = lnl(nums,n), d = rnl(nums,n);
        return val(nums,a,b,c,d,n);
    }
};
