class Solution {
public:
    string evaluate(string s, vector<vector<string>>& kn) {
        int n = s.size();

        unordered_map<string,string>mp;

        for(auto &ele:kn){
            mp[ele[0]] = ele[1];
        }

        auto compute = [&](int &i)->string{
            string t = "";
            i++;
            while(i<n && s[i]!=')'){
                t+=s[i];
                i++;
            }
            i++;

            if(!mp.count(t)) return "?";

            return mp[t];
        };

        string ans = "";

        int i = 0;
        while(i<n){
            if(s[i]!='('){
                ans+=s[i];
                i++;
            }else{
                ans+=compute(i);
            }
        }

        return ans;
    }
};
