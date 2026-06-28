class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();

        vector<int>freq(n+1);
        for(auto ele:arr) freq[min(n,ele)]++;

        vector<int>a;

        for(int i=0;i<=n;i++){
            while(freq[i]--) a.push_back(i);
        }

        int strt = 1;

        for(int i=0;i<n;i++){
            if(a[i]>=strt) strt++;
            else if(i!=0 && a[i]==a[i-1]) continue;
            else break;
        }

        return strt-1;
    }
};
