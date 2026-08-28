class Solution {
public:
    /*
        - check if there is any palindromic permutation of s
        - check the first half if it is possible to g
    */

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int>a(26);

        for(auto c:s){
            a[c-'a']++;
        }

        int odd = 0;
        char mid = '#';

        for(int i=0;i<26;i++){
            if(a[i]&1){
                odd++;
                mid = 'a'+i;
            }
            a[i]/=2;
        }

        if(odd>1) return "";

        int hlf = n/2;

        for(int i=0;i<hlf;i++){
            a[target[i]-'a']--;
        }

        if(*min_element(a.begin(),a.end())>=0){
            string left = target.substr(0,hlf);
            string right = left;
            reverse(right.begin(),right.end());
            
            if(odd){
                left+=mid;
            }

            string ans = left+right;

            if(ans>target) return ans;
        }

        for(int i=hlf-1;i>=0;i--){
            char c = target[i];
            a[c-'a']++;
            
            if(*min_element(a.begin(),a.end())>=0){
                for(int j=c-'a'+1;j<26;j++){
                    if(a[j]){
                        string left = target.substr(0,i);
                        left+='a'+j;
                        a[j]--;

                        for(int k=0;k<26;k++){
                            while(a[k]--){
                                left+='a'+k;
                            }
                        }
                        
                        string right = left;
                        reverse(right.begin(),right.end());
                        
                        if(odd){
                            left+=mid;
                        }

                        return left+right;
                    }
                }
            }
        }

        return "";    
    }
};
