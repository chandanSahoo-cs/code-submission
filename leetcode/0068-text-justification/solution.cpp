class Solution {
public:
    void join(string &a, string &b){
        for(auto ele:b){
            a.push_back(ele);
        }
        return;
    }

    vector<string> fullJustify(vector<string>& words, int mxW) {
        vector<string>ans;
        int n = words.size();
        int i=0;
        while(i<n){
            int j=i;
            int cnt=0;
            while(j<n){
                if(cnt+(j-i)+words[j].size()>mxW){
                    j--;
                    break;
                }
                else{
                    cnt+=words[j].size();
                }
                j++;
            }

            if(j==n) j--;
            string keep="";

            if(j-i==0){
                join(keep,words[i]);
                while(keep.size()<mxW){
                    keep.push_back(' ');
                }
            }else if(j==n-1){
                while(i<=j){
                    join(keep,words[i]);
                    if(i!=j) keep.push_back(' ');
                    i++;
                }

                while(keep.size()<mxW){
                    keep.push_back(' ');
                }
            }
            else{
                int gapsz=(mxW-cnt)/(j-i);
                int extra = (mxW-cnt)%(j-i);

                string gap="";
                for(int k=0;k<gapsz;k++){
                    gap.push_back(' ');
                }

                while(i<j){
                    join(keep,words[i]);
                    join(keep,gap);
                    if(extra){
                        keep.push_back(' ');
                        extra--;
                    }
                    i++;
                }

                join(keep,words[i]);
            }
            i=j+1;

            ans.push_back(keep);
        }

        return ans;
    }
};
