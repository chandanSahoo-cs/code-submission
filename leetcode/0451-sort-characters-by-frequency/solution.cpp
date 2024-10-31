class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char,int>chars;

        for(int i=0;i<n;i++){
            chars[s[i]]++;
        }
        vector<pair<int,char>>mp;
        for(auto ele:chars){
            mp.push_back({ele.second,ele.first});
        }
        sort(mp.begin(),mp.end(),[](pair<int,char>&a,pair<int,char>&b){
            return a.first>b.first;
        });

        string ans = "";

        for(auto ele:mp){
            ans+=string(ele.first,ele.second);
        }

        return ans;
    }

    
};
