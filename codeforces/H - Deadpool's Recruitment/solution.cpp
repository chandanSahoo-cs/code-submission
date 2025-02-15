//#define DEBUG
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
#include <iomanip>
 
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
 
using namespace std;
 
//using namespace __gnu_pbds;
 
//template<class T> using pbds = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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
    f(i,0,s.size()) cout << s[i]; 
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
 
// Solution function
void solve() {
    // Code logic
    int n,t1,t2,k;
    cin >> n>>t1>>t2>>k;
 
    vector<pair<double, int>> prr; 
 
    f(i,0,n) {
        int a,b;
        cin >>a>>b;
 
        double red = (100.00-k)/100.00;
 
        double o1 = (a*t1)*red+b*t2;
        double o2= (b*t1)*red+a*t2;
 
        double maxx =max(o1, o2);
 
        prr.emplace_back(-maxx, i + 1); 
    }
 
    sort(all(prr)); 
    cout << fixed << setprecision(2);
    for (const auto &p : prr) {
    cout << p.second << " " << -p.first << endl;
    }
}
 
// Main function
signed main() {
    #ifdef DEBUG
    auto begin = chrono::high_resolution_clock::now();
    #endif
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int t=1;
    //cin >> t;
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