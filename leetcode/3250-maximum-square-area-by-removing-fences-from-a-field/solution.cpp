const int mod = 1e9+7;

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {

        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());

        unordered_set<long long>hgap;

        hgap.insert(m-1);

        for(int i=0;i<hFences.size();i++){
            hgap.insert(hFences[i]-1);
            hgap.insert(m-hFences[i]);

            for(int j=i+1;j<hFences.size();j++){
                hgap.insert(hFences[j]-hFences[i]);
            }
        }

        long long mx = -1;

        if(hgap.count(n-1)){
            mx = max(mx,(n-1)*1LL*(n-1));
        }

        for(int i=0;i<vFences.size();i++){
            long long up = vFences[i]-1;
            long long down = n-vFences[i];

            if(hgap.count(up)){
                mx = max(mx,up*1LL*up);
            }

            if(hgap.count(down)){
                mx = max(mx,down*1LL*down);
            }

            for(int j=i+1;j<vFences.size();j++){
                long long v = vFences[j]-vFences[i];
                if(hgap.count(v)){
                    mx = max(mx,v*v);
                }
            }
        }



        return mx%mod;;
    }
};
