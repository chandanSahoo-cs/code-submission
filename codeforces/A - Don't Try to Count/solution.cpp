#include <iostream>
#include <string>
 
using namespace std;
 
int minOperationsToSubstring(string x, string s) {
    int minOps = 0;
    if (x.find(s)!=string::npos) return minOps;
 
    while (x.length() <= 25) {
        x += x;
        minOps++;
 
        if (x.find(s) != string::npos) {
            return minOps;
        }
    }
 
    return -1;
}
 
int main() {
    int t;
    cin >> t;
 
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;
 
        int result = minOperationsToSubstring(x, s);
        cout << result << endl;
    }
 
    return 0;
}