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
    optimize();

    int t;
    cin >> t;

    while (t--)
     {
        int n;
        cin >> n;

        string s;
        cin >> s;

        const int INF = 1e9;

        vector<int> pre(n + 1, INF), suf(n + 1, INF);

        pre[0] = 0;
        if (s[0] == '0') {
            int ones = 0;
            for (int i = 1; i <= n; i++) {
                if (s[i - 1] == '1') ones++;
                pre[i] = ones;
            }
        }

        vector<int> zeroSuffix(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            zeroSuffix[i] = zeroSuffix[i + 1] + (s[i] == '0');
        }

        suf[n] = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1')
                suf[i] = zeroSuffix[i + 1];
        }

        int ans = INF;
        for (int k = 0; k <= n; k++) {
            ans = min(ans, pre[k] + suf[k]);
        }
        cout << ans << endl;
    }
    return 0;
}
// https://codeforces.com/contest/2266/problem/C
