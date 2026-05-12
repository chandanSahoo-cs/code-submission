class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[&](vector<int>& v1, vector<int>& v2){
            return v1[1]-v1[0]>v2[1]-v2[0];
        });

        int ans = 0;
        int curr = 0;
        
        for(auto &ele:tasks){
            int act = ele[0], mn = ele[1];
            int diff = max(0,mn-curr);
            ans+=diff;
            curr+=diff-act;
        }

        return ans;
    }
};

/*
1,3 = 3+2 = 5+9=14 + 11 = 25+7=32
2,4 = 2+2 = 4+9=13+11 = 24+7=31
10,11 = 2+9 = 11+11 = 22+7 = 29
10,12 = 1+11 = 12+7 = 19
8,9 = 2+7 = 9
*/
