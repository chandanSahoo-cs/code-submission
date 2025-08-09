class Solution {
public:
    bool check(vector<int> &x , vector<int> &y){
        if(x[0]<=y[1] && y[0]<=x[1]) return true;
        return false;
    }

    vector<vector<int>> insert(vector<vector<int>>& is, vector<int>& nis) {
        vector<vector<int>>ans;

        if(is.size()==0){
            return {nis};
        }

        bool flag=false;
        if(nis[1]<is[0][0]){
            ans.push_back(nis);
            flag=true;
        }

        int n = is.size();
        for(int i=0;i<n;i++){
            if(flag && check(ans.back(),is[i])){
                int x1=ans.back()[0];
                int x2=ans.back()[1];
                ans.pop_back();
                ans.push_back({min(x1,is[i][0]),max(x2,is[i][1])});
            }
            else if(check(is[i],nis)){
                flag=true;
                ans.push_back({min(is[i][0],nis[0]),max(is[i][1],nis[1])});
            }
            else{
                ans.push_back(is[i]);
                if(nis[0]>is[i][1] && (i==n-1 || nis[1]<is[i+1][0])){
                    ans.push_back(nis);
                    flag=true;
                }
            }
        }

        return ans;
    }
};
