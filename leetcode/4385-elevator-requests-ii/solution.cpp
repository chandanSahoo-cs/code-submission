#define ll long long

class Solution {
public:
    ll dp[1505][1505][2];
    
    ll rec(vector<int>&a, ll l, ll r, ll pos){
        int n = a.size();
        
        if(l==0 && r==n-1) return 0;
        if(dp[l][r][pos]!=-1) return dp[l][r][pos];

        ll mn = LLONG_MAX;

        ll curr = pos?a[r]:a[l];
        ll rem = n-(r-l+1);

        if(l>0){
            ll p = rec(a,l-1,r,0);
            mn = min(mn,rem*abs(curr-a[l-1])+p);
        }

        if(r<n-1){
            ll p = rec(a,l,r+1,1);
            mn = min(mn,rem*abs(curr-a[r+1])+p);
        }

        return dp[l][r][pos] = mn;
    }

    ll elevatorRequests(int n, int start, vector<int>& requests) {
        vector<int>a(requests.begin(),requests.end());
        if(find(a.begin(),a.end(),start)==a.end()){
            a.push_back(start);
        }

        for(int i=0;i<a.size();i++){
            for(int j=0;j<a.size();j++){
                dp[i][j][0] = dp[i][j][1] = -1;
            }
        }

        sort(a.begin(),a.end());

        int idx = lower_bound(a.begin(),a.end(),start)-a.begin();

        return min(rec(a,idx,idx,0),rec(a,idx,idx,1));
    }
};
