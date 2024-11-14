class Solution {
public:
    int minimizedMaximum(int n, vector<int>& q) {
        int m = q.size();
        auto check = [&](int mid){
            int tn = n;
            for(int i=0;i<m;i++){
                tn-=(q[i]+mid-1)/mid;
            }
            if(tn<0) return 2;
            return 3;
        };
        // int mxVal = *max_element(q.begin(),q.end());
        // if(!mxVal) return 0;
        int s=1,e=1e5;
        int ans=1e5;
        while(s<e){
            int mid = s+(e-s)/2;
            if(check(mid)== 3){
                ans=min(mid,ans);
                e=mid;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
   }
};
