class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector <bool> freq(26,false);
        for(int i=0;i<sentence.length();i++){
            freq[sentence[i]-'a']=true;
        }
        for(bool isPresent:freq){
            if(!isPresent) return false;
        }
        return true;
    }
};
