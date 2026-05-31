class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());

        int n = asteroids.size();

        for(int i=0;i<n;i++){
            if(mass>=asteroids[i]) mass=min(100000,mass+asteroids[i]);
            else return false;
        }

        return true;
    }
};
