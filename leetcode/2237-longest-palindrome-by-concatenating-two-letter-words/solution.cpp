class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;

        for(auto ele:words) mp[ele]++;

        int mxOdd=0;
        int cnt=0;

        for(auto [key,value]:mp){
            string rKey = key;
            reverse(rKey.begin(),rKey.end());

            if(mp.find(rKey)==mp.end()) continue;

            int mn = min(value,mp[rKey]);

            if(rKey==key){
                if(mn%2){
                    if(mxOdd<mn){
                        swap(mxOdd,mn);
                    }
                    cnt+=max(0,mn-1);
                }else{
                    cnt+=mn;
                }
            }else{
                cnt+=mn;
            }

            // mp[key]=0;
        }

        return 2*(cnt+mxOdd);
    }
};
