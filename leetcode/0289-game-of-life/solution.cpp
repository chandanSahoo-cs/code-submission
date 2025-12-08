class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();



        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int cnt=0;    
                for(int dr=-1;dr<=1;dr++){
                    for(int dc=-1;dc<=1;dc++){
                        if(dr==0 && dc==0) continue;
                        int r = i+dr;
                        int c = j+dc;

                        if(r<0 || r>=n || c<0 || c>=m) continue;
                        cnt+=(board[r][c]%2);
                    }
                }

                int chng=board[i][j];

                if(cnt<2){
                    chng=0;
                }else if(cnt==2){
                    chng=board[i][j];
                }else if(cnt==3){
                    chng=1;
                }else{
                    chng=0;
                }

                board[i][j] = chng*2+board[i][j];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j] = board[i][j]/2;
            }
        }

        return;
    }
};
