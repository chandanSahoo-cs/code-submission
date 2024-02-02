class Solution {
    #define ll long long
public:
    vector<int> sequentialDigits(int low, int high) {
        ll storeL=low;
        ll sizeL=log10(low);
        ll frstdgtL=storeL/pow(10,sizeL);
        if(10-frstdgtL<sizeL+1){
            sizeL++;
            frstdgtL=1;
        }
        ll tempdd=frstdgtL+1;
        while((log10(frstdgtL))<sizeL){
            frstdgtL*=10;
            frstdgtL+=(tempdd);
            tempdd++;
        }
        ll nmbrTdd=1;
        for(ll i=1;i<=sizeL;i++){
            nmbrTdd=nmbrTdd*10+1;
        }
        if(frstdgtL<low) frstdgtL+=nmbrTdd;
        int firstDigit = frstdgtL;
        while (firstDigit >= 10) firstDigit /= 10;
        if((10-firstDigit)<sizeL+1){
            sizeL++;
            frstdgtL=1;
            tempdd=frstdgtL+1;
            while((log10(frstdgtL))<sizeL){
                frstdgtL*=10;
                frstdgtL+=(tempdd);
                tempdd++;
            }
        }
        vector<int>ans;
        while(frstdgtL<=high){
            if(frstdgtL%10==0) break;
            // if(10-(frstdgtL/log10(frstdgtL))<sizeL) break;
            ans.push_back(frstdgtL);
            if(frstdgtL%10==9){
                sizeL++;
                frstdgtL=1;
                tempdd=frstdgtL+1;
                while(log10(frstdgtL)<sizeL){
                    frstdgtL*=10;
                    frstdgtL+=(tempdd);
                    tempdd++;
                }
                if(frstdgtL<=high){
                    ans.push_back(frstdgtL);
                }
                nmbrTdd=(nmbrTdd*10)+1;
            }
            frstdgtL+=nmbrTdd;
        }
        return ans;
    }
};
