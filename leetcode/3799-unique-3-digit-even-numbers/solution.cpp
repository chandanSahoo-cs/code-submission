class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();

        vector<int>freq(10);

        for(auto ele:digits){
            freq[ele]++;
        }

        int cnt = 0;
        for(int i=1;i<=9;i++){
            for(int j=0;j<=9;j++){
                for(int k=0;k<=9;k+=2){
                    if(freq[i]>0 && freq[j]>(i==j) && freq[k]>(i==k)+(j==k)) cnt++;
                }
            }
        }

        return cnt;
    }
};
