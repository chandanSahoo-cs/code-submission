class Solution {
public:
    string decodeCiphertext(string encodedText, int n) {
        int sz = encodedText.size();
        if(sz==0) return "";

        int m = sz/n;

        string decipher = "";

        for(int i=0;i<m;i++){
            for(int j=i;j<sz;j+=m+1){
                decipher+=encodedText[j];
            }
        }

        while(decipher.back()==' ') decipher.pop_back();

        return decipher;
    }
};
