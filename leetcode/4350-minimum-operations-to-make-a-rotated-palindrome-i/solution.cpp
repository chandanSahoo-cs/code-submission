class Solution {
public:
    int minOperations(string s) {
        string t = s+s;
        int n = s.size();
        int ans = INT_MAX;
        
        for(int i=0;i<n;i++){
            int cnt = i;
            for(int j=0;j<n/2;j++){
                if(t[i+j]!=t[n-1-j+i]){
                    char a = t[i+j];
                    char b = t[n-1-j+i];

                    cnt+=min((b-a+26)%26,(a-b+26)%26);
                }
            }
            ans = min(ans,cnt);
        }

        return ans;
    }
};
