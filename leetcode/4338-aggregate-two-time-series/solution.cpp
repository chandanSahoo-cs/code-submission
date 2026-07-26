class Solution {
public:
    int search(vector<vector<int>>& a, int trg){
        int n = a.size();
        int l = 0, r = n-1;

        if(a[n-1][0]<trg) return 0;

        int ans = a[n-1][1];

        while(l<=r){
            int m = l+(r-l)/2;

            if(a[m][0]>=trg){
                ans = a[m][1];
                r = m-1;
            }else l = m+1;
        }

        return ans;
    }

    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& series1, vector<vector<int>>& series2) {
        int n = series1.size(), m = series2.size();

        int i = 0,j = 0;
        vector<vector<int>>ans;
        while(i<n && j<m){
            if(series1[i][0]==series2[j][0]){
                int time = series1[i][0];
                int val = series1[i][1] + series2[j][1];
                ans.push_back({time,val});
                i++;
                j++;
            }else if(series1[i][0]<series2[j][0]){
                int time = series1[i][0];
                int val = series1[i][1]+search(series2,time);
                ans.push_back({time,val});
                i++;
            }else{
                int time = series2[j][0];
                int val = series2[j][1]+search(series1,time);
                ans.push_back({time,val});
                j++;
            }
        }

        while(i<n){
            ans.push_back({series1[i][0],series1[i][1]});
            i++;
        }

        while(j<m){
            ans.push_back({series2[j][0],series2[j][1]});
            j++;
        }

        return ans;
    }
};
