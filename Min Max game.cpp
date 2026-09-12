#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/2263/problem/A 
int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int ones = 0, x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            ones += x;
        }

        if (ones >= (n + 1) / 2)
            cout << "Bessie\n";
        else
            cout << "Elsie\n";
    }

    return 0;
}
