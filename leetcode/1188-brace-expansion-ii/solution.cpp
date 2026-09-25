class Solution {
public:
    string s;
    int n; 
    int idx = 0;

    set<string>getUnit(){
        set<string>result;

        if(s[idx]=='{'){
            idx++;
            result = performUnion();
        }else{
            result = {string(1,s[idx])};
        }
        idx++;
        return result;
    }

    set<string>performConcat(){
        set<string>result={""};

        while(idx<n && (s[idx]=='{' || (s[idx]>='a' && s[idx]<='z'))){
            set<string> temp = getUnit();

            set<string>concatResult;
            for(auto &pref:result){
                for(auto &suff:temp){
                    concatResult.insert(pref+suff);
                }
            }

            result = concatResult;
        }

        return result;
    }

    set<string> performUnion(){
        set<string> result;

        while(true){
            set<string>temp = performConcat();
            result.insert(temp.begin(),temp.end());

            if(idx<n && s[idx]==',') idx++;
            else break;
        }

        return result;
    }

    vector<string> braceExpansionII(string exp) {
        s = exp;
        n = exp.size(); 
        idx = 0;


        set<string> st = performUnion();
        vector<string>ans(st.begin(),st.end());

        return ans;  
    }
};
