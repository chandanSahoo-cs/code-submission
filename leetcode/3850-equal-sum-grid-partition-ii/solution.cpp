#define ll long long

class Solution {
public:
    bool ver(vector<vector<int>>&grid, ll sum, unordered_map<ll,ll>mp){
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<ll,ll>currMp;

        ll currSum = 0;


        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                currSum+=grid[i][j];
                currMp[grid[i][j]]++;
                mp[grid[i][j]]--;
            }

            ll otherSum = sum-currSum;

            // cout<<currSum<<" "<<otherSum<<"\n";
            
            if(otherSum==currSum) return true;

            if(j==0){
                if(currSum-grid[0][0]==otherSum || currSum-grid[n-1][0]==otherSum) return true;
            }else{
                if(n==1){
                    if(currSum-grid[0][0]==otherSum|| currSum-grid[0][j]==otherSum) return true;
                }else{
                    ll tr = currSum-otherSum;
                    if(currMp.find(tr)!=currMp.end() && currMp[tr]>0) return true;
                }
            }

            if(j==m-2){
                if(otherSum-grid[0][m-1]==currSum || otherSum-grid[n-1][m-1]==currSum) return true;
            }else{
                if(n==1){
                    if(otherSum-grid[0][j+1]==currSum || otherSum-grid[0][m-1]==currSum) return true;
                }else{
                    ll tr = otherSum-currSum;
                    if(mp.find(tr)!=mp.end() && mp[tr]>0) return true;
                }
            }
        }

        return false;
    }

    bool hor(vector<vector<int>>&grid, ll sum, unordered_map<ll,ll>mp){
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<ll,ll>currMp;

        ll currSum = 0;

        for(int i=0;i<n-1;i++){

            for(int j=0;j<m;j++){
                currSum+=grid[i][j];
                currMp[grid[i][j]]++;
                mp[grid[i][j]]--;
            }

            ll otherSum = sum-currSum;

            if(otherSum==currSum) return true;

            if(i==0){
                if(currSum-grid[0][0]==otherSum || currSum-grid[0][m-1]==otherSum) return true;
            }else{
                if(m==1){
                    if(currSum-grid[0][0]==otherSum || currSum-grid[i][0]==otherSum) return true;
                }else{
                    ll tr = currSum-otherSum;
                    if(currMp.find(tr)!=currMp.end() && currMp[tr]>0) return true;
                }
            }

            if(i==n-2){
                if(otherSum-grid[n-1][0]==currSum || otherSum-grid[n-1][m-1]==currSum) return true;
            }else{
                if(m==1){
                    if(otherSum-grid[i+1][0]==currSum || otherSum-grid[n-1][0]==currSum) return true;
                }else{
                    ll tr = otherSum-currSum;
                    if(mp.find(tr)!=mp.end() && mp[tr]>0) return true;
                }
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        unordered_map<ll,ll>mp;
        ll sum=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[grid[i][j]]++;
                sum+=grid[i][j];
            }
        }


        return hor(grid,sum,mp) | ver(grid,sum,mp);
    }
};

/*
Disconnect : when on index 0 or index n-1

Store value map
*/
