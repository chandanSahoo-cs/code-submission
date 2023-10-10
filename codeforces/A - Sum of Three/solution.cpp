#include <iostream>
#include <vector>
using namespace std;
 
bool findTriplet(int n, vector<int> &ans)
{
    if (n < 3)
        return false;
    ans.clear();
    for (int i = 1; i < n; i++)
    {
        if (i % 3 != 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (j % 3 != 0)
                {
                    int k = n - i - j;
                    if (i + j + k == n && k % 3 != 0 && k!=i && k!=j && k>0)
                    {
                        ans.push_back(i);
                        ans.push_back(j);
                        ans.push_back(k);
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    vector<int> n(t);
    for (auto &ele : n)
    {
        cin >> ele;
    }
    for (auto ele : n)
    {
        vector<int> ans;
        bool check = findTriplet(ele, ans);
        if (check)
        {
            cout << "Yes" << endl;
            for (auto ele : ans)
            {
                cout << ele << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}