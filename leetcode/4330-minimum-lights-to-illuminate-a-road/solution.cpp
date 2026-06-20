class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int>marks(n);

        for(int i=0;i<n;i++){
            int v = lights[i];

            if(v!=0){
                marks[max(0,i-v)]+=1;
                if(i+v+1<n){
                    marks[i+v+1]+=-1;
                }
            }
        }

        for(int i=1;i<n;i++){
            marks[i]+=marks[i-1];
        }

        // for(auto ele:marks) cout<<ele<<" ";
        // cout<<"\n";

        for(int i=1;i<n-1;i++){
            if(marks[i-1]==0 && marks[i+1]==0) marks[i]=0;
        }

        int consZero = 0;
        int ans = 0;
        
        for(int i=0;i<n;i++){
            if(marks[i]==0) consZero++;
            else{
                ans+=(consZero+2)/3;
                consZero=0;
            }
        }

        ans+=(consZero+2)/3;

        return ans;
    }
};
