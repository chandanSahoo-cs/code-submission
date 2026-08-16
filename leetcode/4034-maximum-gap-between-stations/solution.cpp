class Solution {
public:
    int maximumGap(string skill, string st) {
        int n = skill.size(), m = st.size();
        vector<vector<int>>alpha(26);

        for(int i=0;i<m;i++){
            alpha[st[i]-'a'].push_back(i);
        }

        vector<int>pref(n);
        vector<int>suff(n);

        int j = 0;
        for(int i=0;i<m;i++){
            if(j<n && skill[j]==st[i]){
                pref[j]=i;
                j++;
            }
        }

        j = n-1;
        for(int i=m-1;i>=0;i--){
            if(j>=0 && skill[j]==st[i]){
                suff[j]=i;
                j--;
            }
        }

        int ans = 0;

        for(int i=0;i<n-1;i++){
            ans = max(ans,suff[i+1]-pref[i]);
        }

        return ans;
    }
};
