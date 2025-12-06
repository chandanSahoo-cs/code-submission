class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;

        for(auto ele:words){
            if(mp.find(ele)==mp.end()){
                mp[ele]=1;
            }else mp[ele]++;
        }

        for(auto [key,value]:mp){
            cout<<key<<" "<<value<<"\n";
        }

        int cnt=0;
        int odd=0;

        // for(auto [key,value]:words){
        //     int scnd=0;

        //     if(tr[0]==tr[1]){
        //         if(value%2)
        //     }
        // }

        for(auto ele:words){
            if(mp[ele]==0) continue;
            int frst=mp[ele];
            int scnd=0;
            
            string tr = "";
            tr.push_back(ele[1]);
            tr.push_back(ele[0]);

            if(tr==ele){
                if(frst%2){
                    if(odd>frst){
                        scnd=frst-1;
                        frst--;
                    }else{
                        scnd=max(0,odd-1);
                        odd=frst;
                        frst=scnd;
                    }
                    // odd = max(odd,frst);
                    // scnd=mn-1;
                }else{
                    scnd = frst;
                }
                cnt+=min(frst,scnd);

            }else{
                if(mp.find(tr)!=mp.end()){
                    scnd=mp[tr];
                }
                cnt+=2*min(frst,scnd);
            }
            // cout<<frst<<" "<<scnd<<" "<<cnt<<"\n";
            mp[ele]=0;
            mp[tr]=0;
        }

        return 2*(cnt+odd);
    }
};
