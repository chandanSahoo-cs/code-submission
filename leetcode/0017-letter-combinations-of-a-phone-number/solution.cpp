class Solution {
public:
    vector<string>ans;
    vector<string> alpha = {"","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

    void fill(string &d, int i, string s){
        if(i==d.size()){

            if(s!="") ans.push_back(s);
            return;
        }
        // string t = "";
        // if(d[i]==t) fill(d,i+1,s);

        for(int j=0;j<alpha[(d[i]-'0')-1].size();j++){
            fill(d,i+1,s+alpha[(d[i]-'0')-1][j]);
        }

        return;
    }

    vector<string> letterCombinations(string digits) {
        fill(digits,0,"");

        return ans;
    }
};
