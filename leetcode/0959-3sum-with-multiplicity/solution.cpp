class Solution {
    const int mod = 1e9+7;
public:
    int threeSumMulti(vector<int>& arr, int target) {
        vector<long long>freq(101);

        for(auto ele:arr){
            freq[ele]++;
        }

        long long cnt=0;

        for(int i=0;i<101;i++){
            for(int j=i;j<101;j++){
                if(freq[i]==0 || freq[j]==0) continue;
                int tr = target-i-j;
                if(tr<0 || tr>100 || freq[tr]==0) continue;
                long long fn = freq[tr];
                long  frst = freq[i];
                long scnd = freq[j];

                if(i==j && j==tr){
                    cnt+=(frst*(frst-1)*(frst-2))/6;
                }else if(i==j && j!=tr){
                    cnt+=fn*(frst*(frst-1))/2;
                }else if(i<j && j<tr){
                    cnt+=frst*scnd*fn;
                }

                // cout<<cnt<<"\n";

            }
        }
        return cnt%(int)mod;
    }
};
