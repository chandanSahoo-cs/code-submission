class Solution {
public:
    vector<string>split(string &s, char del){
        vector<string>res;

        int i=0;


        for(int j=0;j<s.size();j++){
            if(s[j]==del){
                res.push_back(s.substr(i,j-i));
                i=j+1;
            }
        }
        res.push_back(s.substr(i));

        return res;
    }

    bool isValidNumber(string s){
        if(s.size()==0 || s.size()>3) return false;
        for(auto c:s){
            if(!isdigit(c)) return false;
        }
        if(s.size()>1 && s[0]=='0') return false;
        return true;
    }

    bool isRight(char c){
        c = tolower(c);

        if(c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f') return true;
        return false;
    }

    bool isValid(string s){
        for(auto c:s){
            if(!isdigit(c) && !isRight(c)) return false;
        }

        return true;
    }

    bool validateIPv4(string ip){
        auto parts = split(ip,'.');
        if(parts.size()!=4) return false;

        for(auto ele:parts){
            if(!isValidNumber(ele)) return false;
            int num = stoi(ele);

            if(num>255) return false;
        }

        return true;
    }


    bool validateIPv6(string ip){
        auto parts = split(ip,':');
        if(parts.size()!=8) return false;

        for(auto ele:parts){
            if(ele.size()<1 || ele.size()>4) return false;
            if(!isValid(ele)) return false;
        }

        return true;
    }

    string validIPAddress(string queryIP) {
        if(validateIPv4(queryIP)){
            return "IPv4";
        }else if(validateIPv6(queryIP)){
            return "IPv6";
        }

        return "Neither";
    }
};
