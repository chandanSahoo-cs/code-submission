#define ll long long

class Solution {
public:

    vector<vector<vector<int>>>indices;
    vector<vector<ll>>dp;

    vector<int>a;
    vector<vector<int>>b;

    int search(int tr){
        int l = 0, r = a.size()-1;
        int ans = r+1;

        while(l<=r){
            int m = l+(r-l)/2;
            
            if(b[a[m]][0]>tr){
                ans = m;
                r = m-1;
            }else l = m+1;
        }

        return ans;
    }

    ll rec(int i, int j){
        int n = a.size();

        if(j==4 || i>=n) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        vector<int>&curr = b[a[i]];
        int ind = search(curr[1]);

        // not pick
        ll val1 = rec(i+1,j);
        vector<int>ind1 = indices[i+1][j];

        // pick and not overlapping
        ll val2 = curr[2]+rec(ind,j+1);
        vector<int>ind2 = indices[ind][j+1];
        ind2.push_back(a[i]);

        sort(ind2.begin(),ind2.end());

        if(val1>val2){
            dp[i][j] = val1;
            indices[i][j] = ind1;
        }else if(val1<val2){
            dp[i][j] = val2;
            indices[i][j] =ind2;
        }else{

            if(ind1<ind2){
                dp[i][j] = val1;
                indices[i][j] = ind1;
            }else{
                dp[i][j] = val2;
                indices[i][j] = ind2;
            }
        }

        return dp[i][j];
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<int>foo(n);

        iota(foo.begin(),foo.end(),0);
        sort(foo.begin(),foo.end(),[&](int i, int j){
            if(intervals[i][0]==intervals[j][0]){
                return intervals[i][1]<intervals[j][1];
            }
            return intervals[i][0]<intervals[j][0];
        });

        a = foo;
        b = intervals;


        dp.resize(n+1,vector<ll>(5,-1));
        indices.resize(n+1,vector<vector<int>>(5));

        rec(0,0);
        
        return indices[0][0];
    }
};
