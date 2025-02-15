#define DEBUG
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<random>
#include<chrono>
#include<map>
#include<climits>
#include<unordered_set>
#include<queue>
#include<unordered_map>
 
using namespace std;
 
#define int long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define vi vector<long long>
#define vvi vector<vector<long long> >
#define f(i,a,b) for(int i=a;i<b;i++)
#define of(i,a,b) for(int i=a;i>=b;i--)
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define endl '\n'
 
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
int randInt(int l, int r) { return uniform_int_distribution<int>(l, r)(RNG); } 
 
void print_string(string s) {
    f(i,0,(int)s.size()) cout << s[i];  
    cout<<'\n';
}
 
void print_vector(const vi &arr) { 
    for (auto x : arr) cout << x << " ";
    cout << '\n';
}
 
void print_2dvector(const vvi &arr) { 
    if (arr.empty()) return; 
    for (const auto &row : arr) {
        for (auto x : row) cout << x << " ";
        cout << '\n';
    }
}
 
int minn_element(const vi &arr) {
    if (arr.empty()) return LLONG_MAX; 
    return *min_element(all(arr));
}
 
const int lo = 20;
const int maxx = 1e5 + 5;
 
vector<pair<int, int>> adj[maxx];
int up[lo][maxx];
int medge[lo][maxx];
int dep[maxx];
 
void bfs(int r, int n) {
    queue<int> q;
    q.push(r);
    fill(dep, dep + n + 1, -1);
    dep[r] = 0;
    up[0][r] = -1;
    medge[0][r] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto &[v, w] : adj[u]) {
            if (dep[v] == -1) {
                dep[v] = dep[u] + 1;
                up[0][v] = u;
                medge[0][v] = w;
                q.push(v);
            }
        }
    }
}
 
int find(int u, int v) {
    if (dep[u] < dep[v]) swap(u, v);
    of(j,lo-1,0) {
        if (dep[u] - (1 << j) >= dep[v]) {
            u = up[j][u];
        }
    }
    if (u == v) return u;
    of(j,lo-1,0) {
        if (up[j][u] != up[j][v]) {
            u = up[j][u];
            v = up[j][v];
        }
    }
    return up[0][u];
}
 
int check(int u, int ln) {
    if (u == ln) return 0;
    int mval = 0;
    of(j,lo-1,0) {
        if (dep[u] - (1 << j) >= dep[ln]) {
            mval = max(mval, medge[j][u]);
            u = up[j][u];
        }
    }
    return mval;
}
 
void solve() {
    int n, q;
    cin >> n >> q;
 
    f(i, 0, n - 1) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
 
    bfs(1, n);
 
    f(j, 1, lo) {
        f(u, 1, n + 1) {
            if (up[j-1][u] == -1) {
                up[j][u] = -1;
                medge[j][u] = medge[j-1][u];
            } else {
                up[j][u] = up[j-1][up[j-1][u]];
                medge[j][u] = max(medge[j-1][u], medge[j-1][up[j-1][u]]);
            }
        }
    }
 
    while (q--) {
        int u, v;
        cin >> u >> v;
        int lca = find(u, v);
        int mu = check(u, lca);
        int mv = check(v, lca);
        cout << max(mu, mv) << endl;
    }
}
 
signed main() {
    #ifdef DEBUG
    auto begin = chrono::high_resolution_clock::now();
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
 
    #ifdef DEBUG
    auto end = chrono::high_resolution_clock::now();
    cerr << "Time measured: " 
         << chrono::duration_cast<chrono::milliseconds>(end - begin).count() 
         << " ms\n";
    cerr.flush();
    #endif
}