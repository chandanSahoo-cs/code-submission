#define all(a) a.begin(),a.end()
class Solution {
    int dp[1005][1005];

    bool check(string &a, string &b){
        int n = a.size(), m = b.size();
        if(m-n!=1) return false;

        int cnt=0;
        int i=0,j=0;

        while(i<n && j<m){
            if(a[i]==b[j]){
                i++;
                j++;
            }else{
                cnt++;
                j++;
            }

            if(cnt>1) return false;
        }

        return true;
    }

public:
    int rec(vector<string>&a, int curr, int prev){

        int n = a.size();

        if(curr==n+1) return 0;

        if(dp[curr][prev]!=-1) return dp[curr][prev];

        int ans = rec(a,curr+1,prev);

        if(prev==0 || check(a[prev-1],a[curr-1])){
            ans = max(ans,1+rec(a,curr+1,curr));
        }

        return dp[curr][prev] = ans;
    }

    int longestStrChain(vector<string>& a) {
        
        sort(all(a),[](string s1, string s2){
            return s1.size()<s2.size();
        });
        memset(dp,-1,sizeof(dp));
        return rec(a,1,0);
    }
};
