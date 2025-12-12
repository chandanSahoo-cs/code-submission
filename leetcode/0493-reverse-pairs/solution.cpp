class Solution {
public:
    int cnt=0;
    void solve(vector<int>&nums,int i,int j,int m, int r){
        while(i<=m && j<=r){
            if((long long)2*nums[j]<(long long)nums[i]){
                cnt+=m-i+1;
                j++;
            }else i++;
        }
    }

    void merge(vector<int>&nums, int l, int m, int r){
        vector<int>temp;
        int j=m+1;
        int i=l;

        solve(nums,i,j,m,r);

        while(i<=m && j<=r){
            if(nums[j]<nums[i]){
                temp.push_back(nums[j]);
                j++;
            }else{
                temp.push_back(nums[i]);
                i++;
            }
        }

        while(i<=m){
            temp.push_back(nums[i]);
            i++;
        }

        while(j<=r){
            temp.push_back(nums[j]);
            j++;
        }

        int z=0;
        for(int k=l;k<=r;k++){
            nums[k]=temp[z];
            z++;
        }
    }

    void mergeSort(vector<int>&nums,int l, int r){
        if(l>=r) return;
        
        int mid = l+(r-l)/2;

        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,r);
        merge(nums,l,mid,r);
    }

    int reversePairs(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return cnt;
    }
};
