#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define testcase int t; cin>>t; while(t--)
#define yes cout << "YES"<<endl;
#define no cout << "NO"<<endl;


int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> b;
        int ballast = 0;
        b.reserve(n);

        for (int i = 0; i < n; i++) {
            long long x;
            cin >> x;
            b.push_back(x - (i + 1));
        }

        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());

        int ans = 1, cur = 1;

        for (int i = 1; i < (int)b.size(); i++) {
            if (b[i] == b[i - 1] + 1)
                cur++;
            else
                cur = 1;

            ans = max(ans, cur);
        }

        cout << ans << '\n';
    }
    return 0;
}
// https://codeforces.com/contest/2266/problem/D
