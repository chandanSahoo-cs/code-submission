class Solution {
public:
    int minDist(int q, int i, int n){
        return min((q-i+n)%n,(i-q+n)%n);
    }

    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        vector<int>ans;

        for(auto &q:queries){
            int ele = nums[q];
            int m = mp[ele].size();
            int ind = lower_bound(mp[ele].begin(),mp[ele].end(),q) - mp[ele].begin();

            if(m==1){ 
                ans.push_back(-1);
                continue;
            }

            int left = minDist(q,ind>0?mp[ele][ind-1]:mp[ele][m-1],n);
            int right = minDist(q,ind<m-1?mp[ele][ind+1]:mp[ele][0],n);

            ans.push_back(min(left,right));
        }

        return ans;
    }
};
