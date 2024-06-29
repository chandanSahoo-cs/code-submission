class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n=tiles.size();
        sort(tiles.begin(),tiles.end());
        vector<int>prefixArr(n);
        for(int i=0;i<n;i++){
            prefixArr[i]=tiles[i][1]-tiles[i][0]+1;
            if(i>0) {
                prefixArr[i]+=prefixArr[i-1];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int s=i,e=n-1,target=tiles[i][0]+carpetLen-1;
            while(s<=e){
                int mid=(e+s)/2;
                if(tiles[mid][0]<=target) s=mid+1;
                else e=mid-1;
            }
            if(tiles[e][0]<=target) s=e;
            int add=target>tiles[s][1]?tiles[s][1]:target;
            int prefix=s>0?prefixArr[s-1]:0;
            int prefix1=i>0?prefixArr[i-1]:0;
            int val=add-tiles[s][0]+1 + prefix-prefix1;
            ans=ans>val?ans:val;
        }
        return ans;
    }
};
