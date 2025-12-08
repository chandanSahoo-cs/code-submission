class Solution {
public:
    int digSum(int n){
        int sum=0;
        
        while(n>0){
            sum+=(n%10);
            n/=10;
        }

        return sum;
    }

    int maximumSum(vector<int>& nums) {

        map<int,pair<int,int>>mp;

        for(auto ele:nums){
            int sum = digSum(ele);

            if(mp.find(sum)==mp.end()){
                mp[sum] = {-ele-1,ele};
            }else{
                if(mp[sum].second<=ele){
                    mp[sum].first = mp[sum].second;
                    mp[sum].second = ele;
                }else if(mp[sum].first<ele){
                    mp[sum].first=ele;
                }
            }
        }

        int mx = -1;

        for(auto [key,value]:mp){
            mx = max(mx,value.first+value.second);
        }

        return mx;    
    }
};
