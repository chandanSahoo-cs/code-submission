class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int n, int m, int rStart, int cStart) {
        int r = rStart, c = cStart;

        vector<vector<int>>ans;

        ans.push_back({r,c});
        if(ans.size()==n*m) return ans;
        
        int mov = 0;

        bool flag = false;

        while(!flag){

            mov++;

            if(!flag){
                for(int k=0;k<mov;k++){
                    c++;
                    if(r>=0 && r<n && c>=0 && c<m){
                        ans.push_back({r,c});
                        if(ans.size()==n*m){
                            flag=true;
                            break;
                        }
                    }
                }
            }

            if(!flag){
                for(int k=0;k<mov;k++){
                    r++;
                    if(r>=0 && r<n && c>=0 && c<m){
                        ans.push_back({r,c});
                        if(ans.size()==n*m){
                            flag=true;
                            break;
                        }
                    }
                }
            }

            mov++;

            if(!flag){
                for(int k=0;k<mov;k++){
                    c--;
                    if(r>=0 && r<n && c>=0 && c<m){
                        ans.push_back({r,c});
                        if(ans.size()==n*m){
                            flag=true;
                            break;
                        }
                    }
                }
            }

            if(!flag){
                for(int k=0;k<mov;k++){
                    r--;
                    if(r>=0 && r<n && c>=0 && c<m){
                        ans.push_back({r,c});
                        if(ans.size()==n*m){
                            flag=true;
                            break;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
