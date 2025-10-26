class Solution {
public:
    bool check(string &s1, string &s2){
        int n = s1.size();

        int cnt=0;
        for( int i=0;i<n;i++){
            cnt+=(s1[i]!=s2[i]);
            if(cnt>1) return false;
        }

        return true;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& a) {
        int n = a.size();

        vector<int>vis(n);
        queue<vector<int>>q;

        for(int i=0;i<n;i++){
            if(check(a[i],beginWord)){
                q.push({i,1});
                vis[i]=1;
            }
        }

        int ans = INT_MAX;

        while(!q.empty()){
            vector<int>pr = q.front();

            int ind = pr[0];
            int level = pr[1];

            if(a[ind]==endWord){
                ans = min(ans,level);
            }

            q.pop();

            for(int k=0;k<n;k++){
                if( level+1<=min(n,ans) && check(a[k],a[ind]) && !vis[k]){
                    q.push({k,level+1});
                    vis[k]=1;
                }
            }
        }

        if(ans==INT_MAX) return 0;
        return ans+1;
    }
};
