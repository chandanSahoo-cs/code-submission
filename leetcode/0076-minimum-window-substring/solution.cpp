class Solution {
public:

    // bool cmp(unordered_map<char,int>&ref, unordered_map<char,int>&curr){

    //     for(char c='a';c<='z';c++){
    //         if(!ref.count(c)) continue;

    //         if(!curr.count(c)) return false;
    //         if(ref[c]>curr[c]) return false;
    //     }


    //     for(char c='A';c<='Z';c++){
    //         if(!ref.count(c)) continue;

    //         if(!curr.count(c)) return false;
    //         if(ref[c]>curr[c]) return false;
    //     }

    //     return true;
    // }


    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();

        unordered_map<char,int>curr,ref;

        for(auto c:t){
            ref[c]++;
        }

        int l = 0, r = 0;

        int al=0,ar=n+1;

        int cnt = 0;

        while(r<n){
            curr[s[r]]++;

            if(curr[s[r]]<=ref[s[r]]) cnt++;
            
            while(cnt==m){
                if(ar-al+1>r-l+1){
                    ar = r;
                    al = l;
                }

                curr[s[l]]--;

                if(curr[s[l]]<ref[s[l]]) cnt--; 
                l++;
            }

            r++;
        }
            

        if(ar==n+1) return "";
        return s.substr(al,ar-al+1);
    }
};
