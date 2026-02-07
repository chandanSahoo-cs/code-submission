class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        
        int n = edges.size();

        vector<int>mark1(n,-1),mark2(n,-1);

        int curr1 = node1;
        int cnt1 = 0;

        while(curr1!=-1 && mark1[curr1]==-1){
            mark1[curr1]=cnt1++;
            curr1 = edges[curr1];
        }

        int curr2 = node2;
        int cnt2=0;

        int dist=-1;
        int ans=-1;

        while(curr2!=-1 && mark2[curr2]==-1){
            mark2[curr2]=cnt2++;

            if(mark1[curr2]!=-1){
                if(dist==-1){
                    dist=max(mark1[curr2],mark2[curr2]);
                    ans=curr2;
                }else{
                    if(dist>max(mark1[curr2],mark2[curr2])){
                        dist = max(mark1[curr2],mark2[curr2]);
                        ans = curr2;
                    }else if(dist==max(mark1[curr2],mark2[curr2])){
                        ans = min(ans,curr2);
                    }
                }
            }
            curr2=edges[curr2];
        }

        return ans;
    }
};
