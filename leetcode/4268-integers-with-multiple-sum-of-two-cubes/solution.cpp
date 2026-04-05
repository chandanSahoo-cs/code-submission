class Solution {
public:
    int cube(int i){
        return i*i*i;
    }
    
    vector<int> findGoodIntegers(int n) {

        vector<int>ans;
        unordered_map<int,int>mp;
        
        for(int i=1;i<=1000;i++){
            for(int j=i;j<=1000;j++){
                int sum = cube(i)+cube(j);
                if(sum<=n) mp[sum]++;
            }
        }

        for(auto &[key,value]:mp){
            if(value>=2) ans.push_back(key);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
