class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& a) {
        int n = a.size();
        sort(a.begin(),a.end());
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            if(a[i]>0) break;
            if(i>0 && a[i]==a[i-1]) continue;
            int l = i+1,r=n-1;

            int tr = -a[i];
            while(l<r){

                if(a[l]+a[r]<tr){
                    l++;
                }else if(a[l]+a[r]>tr){
                    r--;
                }else{
                    ans.push_back({a[i],a[l],a[r]});
                    int tempL = a[l],tempR = a[r];
                    while(a[l]==tempL && l<r) l++;
                    while(a[r]==tempR && l<r) r--;
                }
            }
        }

        return ans;
    }
};
