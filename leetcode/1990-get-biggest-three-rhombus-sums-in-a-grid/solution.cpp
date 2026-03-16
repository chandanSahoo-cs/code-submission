class Solution {
public:
    vector<int>ans;
    void solve(int val){
        for(auto &ele:ans){
            if(ele==val) return;
            if(ele<val){
                swap(ele,val);
            }
        }

        if(ans.size()<3) ans.push_back(val);
    }

    void evaulate(vector<vector<int>>&grid){
        int n = grid.size(), m = grid[0].size();
        int sz = min(n,m);

        for(int s = 0;s<sz;s++){

            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    
                    if(s==0){
                        solve(grid[i][j]);
                    }else{

                        int sum = 0;

                        int k = i-2*(s+1)+2;


                        if(j-s<0 || j+s>=m || k<0) continue;

                        for(int d=0;d<=s;d++){
                            sum+=grid[i-d][j-d];
                            if(d>0) sum+=grid[i-d][j+d];

                            if(d<s) sum+=grid[k+d][j-d];
                            if(d>0 && d<s) sum+=grid[k+d][j+d];
                        }

                        solve(sum);
                    }
                }
            }
        }

        return;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        evaulate(grid);

        return ans;    
    }

};
