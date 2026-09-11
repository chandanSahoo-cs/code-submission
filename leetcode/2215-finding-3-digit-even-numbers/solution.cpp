class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();

        vector<int>freq(10);

        for(auto ele:digits){
            freq[ele]++;
        }

        vector<int>ans;
        for(int i=1;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=9;k+=2){
                    if(freq[i]>0 && freq[j]>(i==j) && freq[k]>(i==k)+(j==k)){
                        ans.push_back(i*100+j*10+k);
                    }
                }
            }
        }

        return ans;
    }
};
