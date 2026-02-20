class Solution {
public:

    void rec(string &s, int l, int r, vector<int>&range){
        if(l>r) return;

        int i = l;
        vector<string>store;

        while(i<=r){
            
            rec(s,i+1,range[i]-1,range);
            store.push_back(s.substr(i,range[i]-i+1));

            i=range[i]+1;
        }

        sort(store.begin(),store.end(),greater());

        i=l;

        for(auto &ele:store){
            for(auto c:ele){
                s[i]=c;
                i++;
            }
        }


        return;
    }

    string makeLargestSpecial(string s) {
        int n = s.size();
        string t = s;

        vector<int>range(n);

        stack<int>st;

        for(int i=0;i<n;i++){
            if(t[i]=='1'){
                st.push(i);
            }else{
                range[st.top()]=i;
                range[i]=-1;
                st.pop();
            }
        }

        if(range[0]==n-1){
            rec(t,1,n-2,range);
        }else{
            rec(t,0,n-1,range);
        }

        return t;
    }
};

// 11011000
// (()(())) 

// 72#65###
// 01234567
