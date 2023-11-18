#include <iostream>
using namespace std;
 
int main() {
    int t;
    cin >> t; // Input the number of test cases
 
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n; // Input an integer for each test case
 
        // Check the condition and output "First" or "Second"
        if (((n - 1) % 3 == 0) || ((n + 1) % 3 == 0))
            cout << "First" << endl;
        else
            cout << "Second" << endl;
    }
 
    return 0;
}