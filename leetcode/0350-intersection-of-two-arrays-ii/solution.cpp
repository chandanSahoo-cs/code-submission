class Solution {
    #define ll long long
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // vector<int>nums1=nums1;
        // sort(nums1.begin(),nums1.end());
        // vector<int>nums2=nums2;
        // sort(nums2.begin(), nums2.end());
        // // ll sizeL=nums1.size(),sizeS=nums2.size();
        // // if(nums1.size()<=nums2.size()){
        // //     swap(large,nums2);
        // //     swap(sizeL,sizeS);
        // // }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        vector<int>store;
        for(ll i=0;i<nums2.size();i++){
            ll target=nums2[i];
            ll s=0,e=nums1.size()-1;
            while(s<=e){
                ll m=s+(e-s)/2;
                if(nums1[m]==target){
                    store.push_back(nums1[m]);
                    nums1.erase(nums1.begin()+m);
                    break;
                }
                else if(nums1[m]<target) s=m+1;
                else e=m-1;
            }
        }
        return store;
    }   
};
