class Solution {
public:
    int passwordStrength(string password) {
        int n = password.size();
        string special = "!@#$";

        int cnt = 0;

        for(char c='a';c<='z';c++){
            for(auto ele:password){
                if(c==ele){
                    cnt++;
                    break;
                }
            }
        }
        
        for(char c='A';c<='Z';c++){
            for(auto ele:password){
                if(c==ele){
                    cnt+=2;
                    break;
                }
            }
        }
        
        for(char c='0';c<='9';c++){
            for(auto ele:password){
                if(c==ele){
                    cnt+=3;
                    break;
                }
            }
        }
        
        for(auto c:special){
            for(auto ele:password){
                if(c==ele){
                    cnt+=5;
                    break;
                }
            }
        }

        return cnt;
    }
};
