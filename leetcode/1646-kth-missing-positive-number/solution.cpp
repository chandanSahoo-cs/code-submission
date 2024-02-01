class Solution {
    #define ll long long
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(k<arr[0]) return k;
        if(arr[arr.size()-1]==arr.size()) return k+arr.size();
        ll s=0,e=arr.size()-1,store;
        while(s<=e){
            ll m=s+(e-s)/2;
            if(arr[m]-(m+1)<k){
                store=m;
                s=m+1;
            }
            else e=m-1;
        }
        return arr[store]+(k-(arr[store]-(store+1)));
    }
};
