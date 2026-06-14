class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int mx = -1;

        for(int i=0;i<n;i++){
            unordered_map<int,int>mp;
            unordered_map<int,int>freqMap;

            bool flag = true;

            for(int j=i;j<n;j++){
                if(freqMap.count(mp[nums[j]])){
                    freqMap[mp[nums[j]]]--;
                    if(freqMap[mp[nums[j]]]==0){
                        freqMap.erase(mp[nums[j]]);
                    }
                }

                mp[nums[j]]++;
                freqMap[mp[nums[j]]]++;

                if(j!=i){
                    if(nums[j-1]!=nums[j]) flag=false;
                }

                if(flag){
                    mx = max(mx,j-i+1);
                }else{
                    if(freqMap.size()>2) flag=false;
                    else{
                        int val1=-1, val2 = -1;
                        for(auto &[key,value]:freqMap){
                            if(val1==-1) val1 = key;
                            else val2 = key;
                        }

                        if(max(val1,val2)==2*min(val1,val2)){
                            mx = max(mx,j-i+1);
                        }
                    }
                }
            }
        }

        return mx;
    }
};
