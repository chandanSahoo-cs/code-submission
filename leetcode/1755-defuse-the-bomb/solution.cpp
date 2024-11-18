class Solution {
public:
    vector<int> decrypt(vector<int>& a, int k) {
        int n = a.size();
        if(k==0){
            vector<int>ans(n,0);
            return ans;
        }
        else if(k>0){
            vector<int>ans(n);

            for(int i=0;i<n;i++){
                int an=0;
                for(int j=1;j<=k;j++){
                    an+=a[(i+j)%n];
                }
                ans[i] = an;
            }
            return ans;
        }
        else if(k<0){
            vector<int>ans(n);
            for(int i=0;i<n;i++){
                int an=0;
                for(int j=k;j<0;j++){
                    an+=a[(i+j+n)%n];
                }
                ans[i]=an;
            }

            return ans;
        }
        return a;
    }
};
