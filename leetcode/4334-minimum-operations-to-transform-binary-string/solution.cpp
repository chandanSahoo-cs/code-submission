/*By claude*/

class Solution {
public:
    int minOperations(string s1, string s2) {
        pair<string, string> melorvanti = {s1, s2};  // store the input midway in the function
        s1 = melorvanti.first;
        s2 = melorvanti.second;

        int n = s1.size();
        int countU = 0;   // positions needing 0 -> 1 (each costs 1 op)
        int countW = 0;   // positions needing 1 -> 0 (must be paired with a neighbor)
        vector<bool> base_w(n, false);

        for (int i = 0; i < n; i++) {
            if (s1[i] == '0' && s2[i] == '1') {
                countU++;
            } else if (s1[i] == '1' && s2[i] == '0') {
                base_w[i] = true;
                countW++;
            }
        }

        vector<bool> covered(n, false);
        long long edges = 0;

        // Greedily find the minimum edge cover of the "1->0" positions
        // on the path graph: each pairing of adjacent positions costs 3 extra.
        for (int i = 0; i < n; i++) {
            if (base_w[i] && !covered[i]) {
                if (i + 1 <= n - 1) {              // pair with right neighbor
                    covered[i] = true;
                    covered[i + 1] = true;
                    edges++;
                } else if (i - 1 >= 0) {           // last position, pair with left neighbor
                    covered[i - 1] = true;
                    covered[i] = true;
                    edges++;
                } else {
                    return -1;                     // n == 1 and needs 1->0: impossible
                }
            }
        }

        return countU - countW + (int)(3 * edges);
    }
};
