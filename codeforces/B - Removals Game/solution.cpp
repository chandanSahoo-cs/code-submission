/*It is not the matter of if, it is the matter of when*/
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define testcases ll tsts; cin >> tsts; while(tsts--)
#define all(x) begin(x), end(x)
// #define push_back(x) emplace_back(x);
#define push(x) emplace(x);
#define insert(x) emplace(x);
int main() {
    fastio
    testcases {
            ll n;cin>>n;
    deque<ll>a;
    deque<ll>b;
        for(ll i = 0; i < n; ++i) {
            ll ele; cin >> ele;
            a.push_back(ele);
        }
        for(ll i = 0; i < n; ++i) {
            ll ele; cin >> ele;
            b.push_back(ele);
        }
        bool flag=true;
        while(flag && !a.empty() && !b.empty()){
            if(a.front()!=b.front() && a.front()!=b.back() && a.back()!=b.front() && a.back()!=b.back()){
                flag=false;
            }
            else{
                if(a.front()!=b.front() && a.front()!=b.back()){
                    a.pop_front();
                    if(a.back()==b.front()){
                        b.pop_front();
                    }
                    else b.pop_back();
                }
                else if(a.back()!=b.front() && a.back()!=b.back()){
                    a.pop_back();
                    if(a.front()==b.front()){
                        b.pop_front();
                    }
                    else b.pop_back();
                }
                else{
                    if(a.front()==b.front()){
                        a.pop_front();
                        b.pop_front();
                    }
                    else if(a.back()==b.front()){
                        a.pop_back();
                        b.pop_front();
                    }
                    else if(a.front()==b.back()){
                        a.pop_front();
                        b.pop_back();
                    }
                    else{
                        a.pop_back();
                        b.pop_back();
                    }
                }
            }
        }
    if(flag) cout<<"Bob"<<"\n";
    else cout<<"Alice"<<"\n";
    }
    return 0;
}