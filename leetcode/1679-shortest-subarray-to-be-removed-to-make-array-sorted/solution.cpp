class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& a) {
        int n = a.size();
        int pref=0;
        int suff=n-1;
        for(int i=1;i<n;i++){
            if(a[i]>=a[i-1]) pref++;
            else break;
        }
        for(int i = n-2;i>=0;i--){
            if(a[i]<=a[i+1]) suff--;
            else break;
        }

        int l=0,r=suff;
        int ans=n;
        while(l<=pref && r<n){
            while(r<n && a[l]>a[r]){
                r++;
            }
            ans=min(r-l-1,ans);
            l++;
        }
        return max({0,min({ans,n-1-pref,suff})});
    }
};
