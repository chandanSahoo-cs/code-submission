class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int>freq(26);

        for(auto c:s){
            freq[c-'a']++;
        }

        for(auto c:target){
            freq[c-'a']--;
        }

        for(int i=n-1;i>=0;i--){
            char c = target[i];
            freq[c-'a']++;

            if(*min_element(freq.begin(),freq.end())>=0){
                string part = "";
                for(int j=c-'a'+1;j<26;j++){
                    if(freq[j]){
                        part+=j+'a';
                        freq[j]--;

                        for(int k=0;k<26;k++){
                            while(freq[k]--){
                                part+=k+'a';
                            }
                        }

                        return target.substr(0,i)+part;
                    }
                }
            }
        }

        return "";
    }
};
