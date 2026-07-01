class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();

        int l = 0, r = 0;

        int sum = 0;
        int cnt = 0;

        while(r<n){
            sum+=arr[r];
            if(r-l+1==k){
                cnt+=((sum/k)>=threshold);
                sum-=arr[l];
                l++;        
            }
            r++;
        }

        return cnt;
    }
};
