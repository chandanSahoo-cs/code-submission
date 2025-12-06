class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& a) {
        int n = a.size();
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            vector<int>store;
            for(int j=0;j<n;j++){

                if(i-1<0 || i+1>=n || j-1<0 || j+1>=n) continue;

                int mx=a[i][j];

                for(int r=-1;r<=1;r++){
                    for(int c=-1;c<=1;c++){
                        mx=max(mx,a[i+r][j+c]);
                    }
                }
                store.push_back(mx);
            }
            if(store.size()) ans.push_back(store);
        }

        return ans;
    }
};
