class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26);
            string k = "";
            for(int j=i;j<n;j++){
                k+=s[j];
                int ind = s[j]-'a';
                freq[ind]+=1;
                int mx = *max_element(freq.begin(),freq.end());
                int mn = findMin(freq);
                ans+=mx-mn;
            }

        }
        return ans;
    }
private:
    int findMin(vector<int>&freq){
        int mn=INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i]==0) continue;
            else{
                if(freq[i]<mn){
                    mn = freq[i];
                }
            }
        }
        return mn;
    }
};
