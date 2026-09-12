#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        if (k < n || k > 2 * n - 1) {
            cout << -1 << '\n';
            continue;
        }

        vector<vector<int>> a(n, vector<int>(n, 0));

        int p = 2 * n - k;
        int cur = 1;

        for (int i = 0; i < p; i++) {
            a[i][i] = cur++;
        }

        for (int i = p; i < n; i++) {
            a[i][0] = cur++;
        }

        for (int j = p; j < n; j++) {
            a[0][j] = cur++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == 0) {
                    a[i][j] = cur++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << a[i][j] << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}

// https://codeforces.com/contest/2263/problem/B
