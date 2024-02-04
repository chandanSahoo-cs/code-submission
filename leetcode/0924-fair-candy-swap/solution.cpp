class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int sumA=0;
        int sumB=0;
        for(int i=0;i<aliceSizes.size();i++){
            sumA+=aliceSizes[i];
        }
        for(int i=0;i<bobSizes.size();i++){
            sumB+=bobSizes[i];
        }
        vector<int>ans;
        bool flag=true;
        sort(bobSizes.begin(),bobSizes.end());
        // sort(aliceSizes.begin(),aliceSizes.end());
        int totSum=sumA-sumB;
        for(int i=0;i<aliceSizes.size();i++){
            int s=0,e=bobSizes.size()-1;
            if(!flag) break;
            while(s<=e){
                int m=s+(e-s)/2;
                if(totSum+2*bobSizes[m]==2*aliceSizes[i]){
                    ans.push_back(aliceSizes[i]);
                    ans.push_back(bobSizes[m]);
                    flag=false;
                    break;
                }
                else if (totSum+2*bobSizes[m]<2*aliceSizes[i]) s=m+1;
                else e=m-1;
            }
        }
        return ans;
    }
};
