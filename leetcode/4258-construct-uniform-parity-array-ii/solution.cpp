class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        set<int>odd;

        for(auto &ele:nums1){
            if(ele&1) odd.insert(ele);
        }

        bool flagEven = true, flagOdd = true;

        // For even
        for(int i=0;i<n;i++){
            if(!(nums1[i]&1)) continue;
            auto it = odd.lower_bound(nums1[i]);

            if(it==odd.begin()){
                flagEven = false;
                break;
            }
        }


        // For odd

        for(int i=0;i<n;i++){
            if(nums1[i]&1) continue;
            auto it = odd.lower_bound(nums1[i]);
            
            if(it==odd.begin()){
                flagOdd=false;
                break;
            }
        }


        return flagEven | flagOdd;
        
    }
};
