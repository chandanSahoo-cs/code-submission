class Solution {
public:
    vector<string> createGrid(int n, int m, int k) {
        vector<string>ans(n,string(m,'#'));

        for(int j=0;j<m;j++){
            ans[0][j] = '.';
        }

        for(int i=0;i<n;i++){
            ans[i][m-1]='.';
        }

        k--;

        for(int j=m-2;j>=0;j--){
            for(int i=1;i<n;i++){
                if(k==0) break;
                ans[i][j]='.';
                k--;
            }

            if(k==0) break;
            if(n!=2) ans[0][m-1]='#';
        }

        if(k>0) return {};
        return ans;
    }
};
