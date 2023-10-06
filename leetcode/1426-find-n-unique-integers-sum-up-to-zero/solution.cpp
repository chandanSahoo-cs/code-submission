class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>integers;
        if(n%2==0){
            for(int i=1;i<=n/2;i++){
                integers.push_back(i);
                integers.push_back(-i);
            }
        }
        else{
            integers.push_back(0);
            for(int i=1;i<=(n-1)/2;i++){
                integers.push_back(i);
                integers.push_back(-i);
            }
        }
        return integers;
        
    }
};
