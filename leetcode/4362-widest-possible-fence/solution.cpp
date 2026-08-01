class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        int n = planks.size();

        unordered_map<int,int>mp,comb;

        int mx = 1;
        for(int i=0;i<n;i++){
            mp[planks[i]]++;

            mx = max(mx,mp[planks[i]]);
        }

        vector<int>a;

        for(auto &[key,value]:mp){
            a.push_back(key);
            comb[key] = value;
        }

        for(int i=0;i<a.size();i++){
            comb[2*a[i]] += mp[a[i]]/2;
            mx = max(mx,comb[2*a[i]]);
            for(int j=i+1;j<a.size();j++){
                comb[a[i]+a[j]] += min(mp[a[i]],mp[a[j]]);
                mx = max(mx,comb[a[i]+a[j]]);
            }
        }

        return mx;

    }
};
