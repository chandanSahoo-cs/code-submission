class LockingTree {
private :
    int n;
    vector<int>locks;
    vector<vector<pair<int,int>>>adj;
public:
    LockingTree(vector<int>& parent) {
        n = parent.size();
        locks.resize(n,-1);
        adj.resize(n);

        for(int i=1;i<n;i++){
            adj[parent[i]].push_back({i,0});
            adj[i].push_back({parent[i],1});
        }
    }
    
    bool lock(int num, int user) {

        if(locks[num]==-1){
            locks[num]=user;
            return true;
        }

        return false;
    }
    
    bool unlock(int num, int user) {
        if(locks[num]==user){
            locks[num]=-1;
            return true;
        }

        return false;
    }

    bool checkUnlockedAncestors(int u){
        if(locks[u]!=-1) return false;

        for(auto [v,p]:adj[u]){
            if(p){
                if(!checkUnlockedAncestors(v)) return false;
            }
        }

        return true;
    }

    bool checkLockedDescendants(int u){
        if(locks[u]!=-1) return true;

        for(auto [v,p]:adj[u]){
            if(!p){
                if(checkLockedDescendants(v)) return true;
            }
        }

        return false;
    }

    void unlockDescendants(int u){
        locks[u]=-1;
        for(auto [v,p]:adj[u]){
            if(!p){
                unlockDescendants(v);
            }
        }

        return;
    }
    
    bool upgrade(int num, int user) {
        if(locks[num]==-1 && checkUnlockedAncestors(num) && checkLockedDescendants(num)){
            unlockDescendants(num);
            locks[num]=user;

            return true;
        }

        return false;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
