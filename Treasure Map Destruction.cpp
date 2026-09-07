#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/2259/problem/E
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> b(n + 1);
        vector<int> diff(n + 2, 0);
        vector<bool> forbidden(n + 1, false);
        vector<bool> treasure_map_fin(n + 1, false);

        bool ok = true;

        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            if (b[i] == 0)
                treasure_map_fin[i] = true;
            else if (b[i] > 0)
                forbidden[i] = true;
        }

        for (int i = 1; i <= n && ok; i++) {
            if (b[i] <= 0) continue;

            int d = b[i];
            if (i - d < 1 && i + d > n) {
                ok = false;
                break;
            }

            int L = max(1, i - d + 1);
            int R = min(n, i + d - 1);
            if (L <= R) {
                diff[L]++;
                diff[R + 1]--;
            }
        }

        int cur = 0;
        for (int i = 1; i <= n && ok; i++) {
            cur += diff[i];
            if (cur > 0) {
                if (treasure_map_fin[i]) {
                    ok = false;
                    break;
                }
                forbidden[i] = true;
            }
        }

        for (int i = 1; i <= n && ok; i++) {
            if (b[i] <= 0) continue;

            int d = b[i];
            int left = i - d;
            int right = i + d;

            bool canLeft = (left >= 1 && !forbidden[left]);
            bool canRight = (right <= n && !forbidden[right]);

            if (!canLeft && !canRight) {
                ok = false;
                break;
            }

            if (canLeft)
                treasure_map_fin[left] = true;
            else
                treasure_map_fin[right] = true;
        }

        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        bool hasTreasure = false;
        for (int i = 1; i <= n; i++)
            hasTreasure |= treasure_map_fin[i];

        if (!hasTreasure)
            treasure_map_fin[1] = true;

        vector<int> dist(n + 1, 1e9);
        queue<int> q;

        for (int i = 1; i <= n; i++) {
            if (treasure_map_fin[i]) {
                dist[i] = 0;
                q.push(i);
            }
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            if (v > 1 && dist[v - 1] > dist[v] + 1) {
                dist[v - 1] = dist[v] + 1;
                q.push(v - 1);
            }
            if (v < n && dist[v + 1] > dist[v] + 1) {
                dist[v + 1] = dist[v] + 1;
                q.push(v + 1);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (b[i] != -1 && dist[i] != b[i]) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << -1 << '\n';
            continue;
        }

        for (int i = 1; i <= n; i++)
            cout << (treasure_map_fin[i] ? '1' : '0');
        cout << '\n';
    }

    return 0;
}
