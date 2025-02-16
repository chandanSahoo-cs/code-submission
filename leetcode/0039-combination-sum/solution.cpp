class Solution {
public:
    vector<vector<int>>ans;
    map<pair<pair<int,int>,vector<int>>,int>mp;

    bool giveAns(vector<int>& a,vector<int> s, int t,int i){
        if(t==0){
            ans.push_back(s);
            return 1;
        }
        if(a.size()==i) return 0;   
        if(mp.find({{i,t},s})!=mp.end()) return mp[{{i,t},s}];

        // if(dp[i][t][rep]!=-1){
        //     return dp[i][t][rep];
        // }

        bool take=false;

        if(t-a[i]>=0){
            s.push_back(a[i]);
            take=giveAns(a,s,t-a[i],i);
            s.pop_back();
        }

        bool notTake = giveAns(a,s,t,i+1);

        return mp[{{i,t},s}]=(take || notTake);
    }

    vector<vector<int>> combinationSum(vector<int>& a, int t) {
        vector<int>s;
        giveAns(a,s,t,0);
        return ans;
    }
};
