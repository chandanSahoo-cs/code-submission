class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();

        vector<int>strt(n),nd(n);

        for(int i=0;i<n;i++){
            if(i==0) strt[i]=1;
            else if(r[i]>r[i-1]) strt[i]=strt[i-1]+1;
            else strt[i]=1;
        }

        for(int i=n-1;i>=0;i--){
            if(i==n-1) nd[i]=1;
            else if(r[i]>r[i+1]) nd[i]=nd[i+1]+1;
            else nd[i]=1;
        }
        
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            ans[i]=max(strt[i],nd[i]);
        }

        int sum = accumulate(ans.begin(),ans.end(),0);

        return sum;
    }
};
