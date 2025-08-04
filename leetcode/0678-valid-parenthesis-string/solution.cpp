class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        stack<char>st;
        vector<int>cnt(n),reverseCnt(n);
        vector<int>order;


        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                continue;
            }
            if(st.empty() || !(st.top()=='(' && s[i]==')')){
                st.push(s[i]);
                order.push_back(i);
            }else{
                st.pop();
                order.pop_back();
            }
        }

        if(st.empty()) return true;

        for(int i=0;i<n;i++){
            if(i==0) cnt[i]=0;
            else cnt[i]=cnt[i-1];

            if(s[i]=='*') cnt[i]++;
        }

        int usedF=0,usedR=0;
        vector<int>keep(n);

        for(int i=0;i<order.size();i++){
            if(s[order[i]]==')'){
                if(cnt[order[i]]-usedF>0){
                    usedF++;
                    keep[order[i]]=1;
                }else return false;
            }
        }

        for(int i=n-1;i>=0;i--){

            if(i==n-1) reverseCnt[i]=0-keep[i];
            else reverseCnt[i]=reverseCnt[i+1]-keep[i];

            if(s[i]=='*') reverseCnt[i]++; 
        }

        int carry=reverseCnt[0];

        for(int i=0;i<order.size();i++){
            if(s[order[i]]=='('){
                int temp = min(carry,reverseCnt[order[i]]);
                if(temp>0){
                    usedR++;
                    carry=temp-1;
                }else return false;
            }
        }

        return true;
    }
};
