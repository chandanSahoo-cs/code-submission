class Solution {
public:

    string compute(int n, int k, int i){
        string t = "";

        while(i){
            t+=('0'+(i&1));
            i>>=1;
        }

        while(t.size()<n){
            t+='0';
        }

        reverse(t.begin(),t.end());

        int sum = 0;
        int cnt = 0;

        for(int i=0;i<n;i++){
            if(t[i]=='1') cnt++;
            else cnt = 0;

            if(cnt==2) return "";

            if(t[i]=='1') sum+=i;
        }

        if(sum<=k) return t;
        return "";
    }

    vector<string> generateValidStrings(int n, int k) {
        
        vector<string>ans;

        for(int i=0;i<=(1<<n)-1;i++){
            string t = compute(n,k,i);

            if(t.size()) ans.push_back(t);
        }

        return ans;
    }
};
