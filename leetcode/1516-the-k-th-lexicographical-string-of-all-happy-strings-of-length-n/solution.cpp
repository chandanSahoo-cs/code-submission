class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3*(1<<(n-1));
        if(k>total) return "";

        string s = "";
        char prev = '#';

        for(int i=0;i<n;i++){
            for(char c='a';c<='c';c++){
                if(prev==c) continue;

                int cnt = 1<<(n-1-i);

                if(k>cnt){
                    k-=cnt;
                }else{
                    s+=c;
                    prev=c;
                    break;
                }
            }
        }

        /*
            k-8
            k=2

        */

        return s;
    }
};
