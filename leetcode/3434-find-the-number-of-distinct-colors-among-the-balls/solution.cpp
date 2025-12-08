class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mark;

        unordered_map<int,int>mp;
        vector<int>ans;

        for(auto ele:queries){
            int x = ele[0];
            int y = ele[1];

            if(mark.find(x)!=mark.end()){
                mp[mark[x]]--;
                if(mp[mark[x]]==0){
                    mp.erase(mark[x]);
                }
            }

            mp[y]++;
            mark[x]=y;

            ans.push_back(mp.size());
        }

        return ans;
    }
};
