#include <bits/stdc++.h>
using namespace std;

int main()
 {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        vector<int> diff(n + 2, 0);

        for (int k = 1; k <= n; k++) {
            long long l = 1LL * k * a[k];
            long long r = 1LL * k * (a[k] + 1) - 1;

            if (l < n) {
                r = min(r, 1LL * n - 1);
                diff[l]++;
                diff[r + 1]--;
            }
        }

        vector<int> safe(n, 0);
        int cur = 0;

        for (int y = 0; y < n; y++) {
            cur += diff[y];
            safe[y] = (cur == 0);
        }

        vector<int> nxt(n + 1, n);
        
        for (int y = n - 1; y >= 0; y--) {
            if (safe[y])
                nxt[y] = y;
            else
                nxt[y] = nxt[y + 1];
        }

        vector<int> B;
        vector<bool> used(n, false);

        for (int k = 1; k <= n; k++) {
            for (int v = 0; v < a[k]; v++) {
                long long l = 1LL * v * k;
                long long r = min(1LL * n - 1, 1LL * (v + 1) * k - 1);

                int y = nxt[l];

                if (y <= r && !used[y]) {
                    used[y] = true;
                    B.push_back(y);
                }
            }
        }

        cout << B.size() << '\n';

        for (int x : B)
            cout << x << ' ';
        cout << '\n';
    }

    return 0;
}

// https://codeforces.com/contest/2263/problem/C1
