class Solution {
public:
    int compare(string &a, string &b){
        int n = a.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) cnt++;
        }

        return cnt;
    }

    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        int n = queries.size(), m = dict.size();

        vector<string>ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(compare(queries[i],dict[j])<=2){
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }

        return ans;
    }
};
