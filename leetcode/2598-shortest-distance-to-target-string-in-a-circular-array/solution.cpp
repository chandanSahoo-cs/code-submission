class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int ind = -1;

        for(int i=0;i<n;i++){
            if(words[i]==target){
                if(ind==-1){
                    ind = min((startIndex-i+n)%n,(i-startIndex+n)%n);
                }else{
                    ind = min({ind,(startIndex-i+n)%n,(i-startIndex+n)%n});
                }
            }
        }

        return ind;
    }
};
