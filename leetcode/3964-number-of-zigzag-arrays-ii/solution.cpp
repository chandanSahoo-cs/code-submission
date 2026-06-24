/*NOT MY SOLUTION*/

#define ll long long
const int mod = 1e9+7;

class Solution {
private:
    vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
        int n = a.size();
        int m = b[0].size();
        vector<vector<ll>> res(n, vector<ll>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < a[0].size(); k++) {
                ll r = a[i][k];
                if (r == 0) {
                    continue;
                }
                for (int j = 0; j < m; j++) {
                    res[i][j] = (res[i][j] + r * b[k][j]) % mod;
                }
            }
        }
        return res;
    }

    vector<vector<ll>> powMul(vector<vector<ll>> base, ll exp, vector<vector<ll>> res) {
        while (exp > 0) {
            if (exp & 1) {
                res = mul(res, base);
            }
            base = mul(base, base);
            exp >>= 1;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;
        if (n == 1) {
            return m;
        }

        int size = 2 * m;
        vector<vector<ll>> u(size, vector<ll>(size, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < i; j++) {
                u[i][j + m] = 1;
            }
            for (int j = i + 1; j < m; j++) {
                u[i + m][j] = 1;
            }
        }

        vector<vector<ll>> dp(1, vector<ll>(size, 1));

        dp = powMul(move(u), n - 1, move(dp));

        ll ans = 0;
        for (int i = 0; i < size; i++) {
            ans = (ans + dp[0][i]) % mod;
        }

        return ans;
    }
};
