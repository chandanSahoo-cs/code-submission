class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses);

        for(auto ele:prerequisites){
            adj[ele[1]].push_back(ele[0]);

            indegree[ele[0]]++;
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(auto ele:adj[curr]){
                indegree[ele]--;

                if(indegree[ele]==0){
                    q.push(ele);
                }
            }
        }

        for(auto ele:indegree){
            if(ele>0) return false;
        }

        return true;
    }
};
