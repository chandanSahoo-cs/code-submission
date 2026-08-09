class Solution {
public:

    int maxArea(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();

        vector<vector<int>>dp1(n+1,vector<int>(m+1)),dp2(n+1,vector<int>(m+1));
        vector<int>top(n),bot(n),left(m),right(m);

        // top-left -> bottom-down
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int right = dp1[i][j+1];
                int down = dp1[i+1][j];
                int dia = dp1[i+1][j+1];

                dp1[i][j] = mat[i][j]==0?0:1+min({right,down,dia});
                top[i] = max(top[i],dp1[i][j]);
                left[j] = max(left[j],dp1[i][j]);
            }
        }

        // bottom-down -> top-left
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int left = j-1<0?0:dp2[i][j-1];
                int up = i-1<0?0:dp2[i-1][j];
                int dia = (i-1<0 || j-1<0)?0:dp2[i-1][j-1];

                dp2[i][j] = mat[i][j]==0?0:1+min({left,up,dia});
                bot[i] = max(bot[i],dp2[i][j]);
                right[j] = max(right[j],dp2[i][j]);
            }
        }

        // getting max left and up - suff, bot and right-pref;

        for(int i=1;i<n;i++){
            bot[i] = max(bot[i],bot[i-1]);
            top[n-1-i] = max(top[n-1-i],top[n-i]);
        }


        for(int j=1;j<m;j++){
            right[j] = max(right[j],right[j-1]);
            left[m-1-j] = max(left[m-1-j],left[m-j]);
        }

        int mx = 0;

        for(int i=0;i<n-1;i++){
            mx = max(mx,min(bot[i],top[i+1]));
        }

        for(int j=0;j<m-1;j++){
            mx = max(mx,min(right[j],left[j+1]));
        }

        return mx*mx;
    }
};

/*
[1,1,0]
[1,1,0]
*/
