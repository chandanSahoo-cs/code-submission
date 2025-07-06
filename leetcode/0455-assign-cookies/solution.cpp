class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if(s.size()==0) return 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int j=s.size()-1;
        int cnt=0;

        for(int i=g.size()-1;i>=0;i--){
            if(s[j]>=g[i]){
                cnt++;
                j--;
            }
            if(j<0) break;
        }

        return cnt;
    }
};
