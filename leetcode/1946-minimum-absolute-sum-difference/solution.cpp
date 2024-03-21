class Solution {
    #define ll long long
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<ll>cmp(nums1.size());
        ll mod =1e9+7;
        ll sum=0;
        //Storing the intial differnce and storing their sum
        for(ll i=0;i<nums1.size();i++){
            cmp[i]=abs(nums1[i]-nums2[i]);
            sum+=abs(nums1[i]-nums2[i]);
        }
        //Sorting the first array (we are only allowed for first)
        sort(nums1.begin(),nums1.end());
        vector<ll>storeArr;
        //Getting the minimum difference for the elements in second array wrt first array and pushing it to another array
        for(ll i=0;i<nums2.size();i++){
            ll s=0,e=nums1.size()-1;
            ll store=INT_MAX;
            while(s<=e){
                ll m=s+(e-s)/2;
                if(nums1[m]==nums2[i]){
                    store=0;
                    break;
                }
                else if(nums1[m]<nums2[i]){
                    store=abs(nums1[m]-nums2[i])<store?abs(nums1[m]-nums2[i]):store;
                    s=m+1;
                }
                else {
                    store=abs(nums1[m]-nums2[i])<store?abs(nums1[m]-nums2[i]):store;
                    e=m-1;
                }
            }
            storeArr.push_back(store);
        }
        //Getting the differnce between (optimal differnce of elements of array 2 and given difference )
        // ll mx=INT_MIN;
        // for(ll i=0;i<nums1.size();i++){
        //     mx=max(mx,abs(storeArr[i]-cmp[i]));
        // }
        // return (sum-mx+mod)%mod;
        vector<ll>temp(nums1.size());
        for(ll i=0;i<nums1.size();i++){
            temp[i]=abs(storeArr[i]-cmp[i]);
        }
        
        auto mx=distance(temp.begin(),max_element(temp.begin(),temp.end()));
        sum=sum-cmp[mx]+storeArr[mx];
        return (sum+mod)%mod;

    }
};
