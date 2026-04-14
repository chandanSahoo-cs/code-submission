#define ll long long 

class Solution {
public:
    ll minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        vector<int>fac;

        for(auto ele:factory){
            while(ele[1]--) fac.push_back(ele[0]);
        }

        sort(fac.begin(),fac.end());
        sort(robot.begin(),robot.end());

        int n = robot.size(), m = fac.size();

        vector<ll>curr(m+1), next(m+1);
        curr[m] = 1e12;

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ll tk = abs(robot[i]-fac[j])+next[j+1];
                ll ntk = curr[j+1];

                curr[j] = min(tk,ntk);
            }

            next = curr;
        }

        return next[0];
    }
};
