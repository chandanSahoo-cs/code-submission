class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        reverse(s.begin(),s.end());

        int l=0;
        int r=0;

        while(r<n){
            if(r!=0 && s[r-1]!=' ' && s[r]==' '){ 

                reverse(s.begin()+l,s.begin()+r);

                while(l<n && s[l]!=' ') l++;
                
                l++;
                r=l;

            }else r++;
        }

        reverse(s.begin()+l,s.begin()+r);

        while(s.back()==' ') s.pop_back();

        return s;
    }
};
