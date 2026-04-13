class Solution {
public:
    void populate(string &text, vector<int>&store, string &a){
        int n = text.size();
        int cnt = 1;

        for(int i=1;i<n;i++){
            if(text[i]==text[i-1]) cnt++;
            else{
                store.push_back(cnt);
                a+=text[i-1];
                cnt=1;
            }
        }

        a+=text.back();
        store.push_back(cnt);

        return;
    }

    int maxRepOpt1(string text) {
        string a;
        vector<int>store;

        populate(text,store,a);

        vector<int>alpha(26);

        for(auto c:text){
            alpha[c-'a']++;
        }

        int mx = 0;

        if(a.size()==1){
            return store[0];
        }
        if(a.size()==2){
            return max(store[0],store[1]);
        }


        for(int i=0;i<a.size()-2;i++){
            mx = max({store[i],store[i+1],store[i+2],mx});
            if(a[i]==a[i+2] && store[i+1]==1){
                int comb = store[i]+store[i+1]+store[i+2];
                if(comb<=alpha[a[i]-'a']){
                    mx = max(mx,comb);
                }else mx =max(mx,comb-1);
            }else{
                int left = store[i]+1<=alpha[a[i]-'a']?store[i]+1:0;
                int right = store[i+2]+1<=alpha[a[i+2]-'a']?store[i+2]+1:0;

                mx = max({mx,left,right});
            }    
        }

        return mx;

    }
    
    /*
    int l = left ind
    int m = prev swap pos = l (init)

    char curr = current character

    for i->n :
        if text[i]==curr:
            tot[curr]>=

    */
};
