class Solution {
public:
    bool search(vector<int>&a, int tr){
        for(int i=0;i<26;i++){
            if(i==tr){
                if(a[i]<=0) return false;
                a[i]--;
                break;
            }
        }

        return true;
    }

    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        
        vector<int>even(26),odd(26);

        for(int i=0;i<n;i++){
            if(i%2){
                odd[s1[i]-'a']++;
            }else{
                even[s1[i]-'a']++;
            }
        }

        for(int i=0;i<n;i++){
            int tr = s2[i]-'a';
            if(!search(i%2?odd:even,tr)) return false;
        }

        return true;
    }
};
