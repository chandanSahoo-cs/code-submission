class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            vector<int>temp;
            int keep = 1;
            for(int j=0;j<=i;j++){
                if(j==0 || j==i) temp.push_back(1);
                else{
                    keep*= i+1-j;
                    keep/=j;
                    temp.push_back(keep);
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
