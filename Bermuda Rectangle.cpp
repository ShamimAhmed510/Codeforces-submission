#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/2257/D
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        ll S;
        int q;
        cin >> S >> q;

        vector<ll> d;

        for (ll i = 1; i * i <= S; ++i) {
            if (S % i == 0) {
                d.push_back(i);

                if (i != S / i)
                    d.push_back(S / i);
            }
        }

        sort(d.begin(), d.end());

        int n = d.size();

        vector<ll> pref(n);

        for (int i = 0; i < n; ++i) {
            ll prev = (i == 0 ? 0 : d[i - 1]);

            pref[i] = (d[i] - prev) * (S / d[i]);

            if (i > 0)
                pref[i] += pref[i - 1];
        }

        auto area = [&](ll x) -> ll {
            if (x == 0)
                return 0;

            int i = lower_bound(d.begin(), d.end(), x) - d.begin();

            ll prev = (i == 0 ? 0 : d[i - 1]);

            ll before = (i == 0 ? 0 : pref[i - 1]);

            return before + (x - prev) * (S / d[i]);
        };

        while (q--) {
            ll x, y;
            cin >> x >> y;

            ll limit = S / y;

            int i = upper_bound(d.begin(), d.end(), limit)
                    - d.begin() - 1;

            ll capped = min(x, d[i]);

            ll ans = capped * y;

            if (x > capped)
                ans += area(x) - area(capped);

            cout << ans << '\n';
        }
    }

    return 0;
}
