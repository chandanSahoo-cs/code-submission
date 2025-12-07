class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mark;
        unordered_map<int,int>mp;

        vector<int>ans;

        for(auto ele:queries){
            int x = ele[0];
            int y = ele[1];

            int cmp=-1;
            if(mark.find(x)!=mark.end()){
                cmp = mark[x];
            }

            if(cmp!=-1){
                mp[cmp]--;
                if(mp[cmp]==0){
                    mp.erase(cmp);
                }
            }

            mark[x]=y;
            if(mp.find(y)==mp.end()){
                mp[y]=1;
            }else mp[y]++;

            ans.push_back(mp.size());
        }

        return ans;
    }
};
