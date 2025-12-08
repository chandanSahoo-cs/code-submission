class Solution {
    const int mod = 1e9+7;
public:
    int threeSumMulti(vector<int>& arr, int target) {
        unordered_map<int,int>mp;

        for(auto ele:arr) mp[ele]++;

        long long cnt=0;

        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                long long a = mp[i];
                long long b = mp[j];

                int tr = target-i-j;
                if(mp.find(tr)==mp.end()) continue;

                long long c = mp[tr];

                if(i==j && j==tr){
                    cnt+=(a*(a-1)*(a-2))/6;
                }else if(i==j && j!=tr){
                    cnt+=((a*(a-1))/2)*c;
                }else if(j<i && i<tr){
                    cnt+=a*b*c;
                } 
            }
        }

        return cnt%mod;
    }
};
