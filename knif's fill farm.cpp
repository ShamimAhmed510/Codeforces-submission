#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl '\n'
#define optimize() ios::sync_with_stdio(false); cin.tie(nullptr);
#define testcase int t; cin>>t; while(t--)
#define yes cout << "YES"<<endl;
#define no cout << "NO" << endl;
const ll NEG = -(1LL << 60);

int main() {
    optimize();

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<ll> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];

        if (m == 1) {
            ll ans = LLONG_MIN;
            for (int i = 1; i <= n; i++)
                ans = max(ans, a[i]);
            cout << ans << endl;
            continue;
        }

        priority_queue<ll> pq;
        ll sum = 0;
        ll ans = LLONG_MIN;

        for (int i = 1; i <= n; i++) {
            if ((int)pq.size() == m - 1) {
                ans = max(ans, 1LL * m * a[i] - sum);
            }

            pq.push(a[i]);
            sum += a[i];

            if ((int)pq.size() > m - 1) {
                sum -= pq.top();
                pq.pop();
            }
        }

        cout << ans << endl;
    }

    return 0;
}
// https://codeforces.com/contest/2264/problem/B
