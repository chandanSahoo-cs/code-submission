class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();

        vector<int>pref(m,n);
        vector<int>suff(m,-1);

        int i = 0;

        for(int j=0;j<n;j++){
            if(word1[j]==word2[i]){
                pref[i]=j;
                i++;
            }

            if(i==m) break;
        }

        i = m-1;

        for(int j=n-1;j>=0;j--){
            if(word1[j]==word2[i]){
                suff[i]=j;
                i--;
            }

            if(i<0) break;
        }

        vector<int>ind;

        for(int i=0;i<m;i++){
            int left = i-1<0?-1:pref[i-1];
            int right = i+1==m?n:suff[i+1];

            if(right-left>=2){
                ind.push_back(i);
            }
        }

        if(ind.size()==-0) return {};

        vector<int>ans;
        i = 0;
        int k = 0;

        for(int j=0;j<n;j++){
            if(word1[j]==word2[i]){
                ans.push_back(j);
                if(k<ind.size() && i==ind[k]) k++;
                i++;
            }else if(k<ind.size() && ind[k]==i){
                ans.push_back(j);
                k=ind.size();
                i++;
            }

            if(i==m) break;
        }        
        return ans;
    }
};
