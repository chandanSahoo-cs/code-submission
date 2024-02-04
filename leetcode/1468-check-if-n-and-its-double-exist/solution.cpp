class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        // for(auto &ele:arr){
        //     ele=abs(ele);
        // }
        sort(arr.begin(),arr.end());
        bool flag=false;
        for(int i=0;i<arr.size();i++){
            int s=0,e=arr.size()-1;
            while(s<=e){
                int m=s+(e-s)/2;

                if(arr[m]==arr[i]*2 && i!=m){
                    flag=true;
                    break;
                }
                // else if(arr[m]==arr[i]/2 && arr[i]%2==0 && arr[i]<0 ){
                //     flag=true;
                //     break;
                // }
                else if(arr[m]<arr[i]*2) s=m+1;
                else e=m-1;
            }
        }
        
        if(flag) return flag;
        else return flag;
    }
};
