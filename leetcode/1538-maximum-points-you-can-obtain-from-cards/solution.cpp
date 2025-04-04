class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int n = a.size();
        int sum=0;

        for(int i=n-k;i<n;i++){
            sum+=a[i];
        }
        int ans=sum;
        int l=n-k,r=n-1;
        for(int i=0;i<k;i++){
            sum-=a[l];
            l = (l+1)%n;
            r = (r+1)%n;
            sum+=a[r];
            ans=max(ans,sum);
        }

        return ans;
    }
};
