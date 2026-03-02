class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        
        vector<int>store;

        for(int i=0;i<n;i++){
            int j = n-1;
            int cnt=0;
            while(j>=0 && grid[i][j]==0){
                cnt++;
                j--;
            }

            store.push_back(cnt);
        }

        vector<int>mark(n);

        int cnt = 0;

        for(int i=n-1;i>=1;i--){
            int reach=0;
            int j = 0;
            for (;j<n;j++){
                if(!mark[j]){
                    if(store[j]>=i){
                        // flag = true;
                        mark[j]=1;
                        break;
                    }
                    reach++;
                }
            }

            if(j==n) return -1;

            cnt+=reach;
        }

        return cnt;
    }
};

/*
+2
0 1 2
2 0 1

1 2 3 4 5
*/

/*
cnt +=-3+4+1 +1
10
9 8 7 6 5 4 3 2 1
6 7 4 9 6 9 7 7 9 4 

9 9 7 6 6 4


*/
