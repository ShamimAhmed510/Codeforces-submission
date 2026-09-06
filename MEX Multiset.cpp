#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        int zeroCnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) zeroCnt++;
        }

        if (zeroCnt == 1) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";

        string ans(n, 'A');

        if (zeroCnt == 0) {
            cout << ans << '\n';
            continue;
        }

        int usedZero = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                if (usedZero == 0) ans[i] = 'A';
                else if (usedZero == 1) ans[i] = 'B';
                else ans[i] = 'A';
                usedZero++;
            } else if (a[i] == 1) {
                ans[i] = 'C';
            } else {
                ans[i] = 'A';
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
