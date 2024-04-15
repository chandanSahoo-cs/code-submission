#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
int main() {
    fastio
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t
    while (t--) {
        int n, c, d;
        cin >> n >> c >> d;
        cin.ignore(); // Ignore the newline character after reading n, c, d
        vector<int> eff(n * n);
        for (int j = 0; j < n * n; j++) {
            cin >> eff[j];
        }
        sort(eff.begin(), eff.end());
        vector<int> a(n * n);
        a[0] = eff[0];
        for (int j = 1; j < n; j++) {
            a[j] = a[j - 1] + c;
        }
        for (int j = 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                a[j * n + k] = a[(j - 1) * n + k] + d;
            }
        }
        sort(a.begin(), a.end());
        cout << (a == eff ? "YES" : "NO") << endl;
    }
    return 0;
}