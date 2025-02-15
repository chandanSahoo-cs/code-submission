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
    int n,m;
    cin>>n>>m;
 
    vector<pair<char, int>>str(n);
    vi prr(n+1,0), mrr(n+1,0);
 
    f(i,0,n) {
        string s;
        cin>>s;
        char t=s[0];
        int j=stoi(s.substr(1));
        str[i]={t, j};
        if (t=='+') {
            prr[j]++;
        } else {
            mrr[j]++;
        }
    }
 
    int sm=accumulate(all(mrr), 0);
 
    vi krr;
    vector<bool>flag(n+1,false);
 
    f(k,1,n+1) {
        int count=prr[k]+(sm-mrr[k]);
        if (count==m) {
            krr.pb(k);
            flag[k] = true;
        }
    }
 
    for (const auto& stmt : str) {
        char type=stmt.first;
        int j=stmt.second;
 
        if (type=='+') {
            if (krr.size()==1 && flag[j]) {
                cout<<"Truthful"<<endl;
            } else if (!flag[j]) {
                cout<<"Enchanted\n";
            } else {
                cout<<"Agamotto failed"<<endl;
            }
        } else {
            if (!flag[j]) {
                cout<<"Truthful"<<endl;
            } else if(krr.size() == 1 && flag[j]) {
                cout<<"Enchanted"<<endl;
            } else {
                cout<<"Agamotto failed"<<endl;
            }
        }
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