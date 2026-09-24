#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long current_sum = 0;
    int first_fail_idx = -1;
    for (int i = 0; i < n; i++) {
        current_sum += a[i];
        if (current_sum < 0) {
            first_fail_idx = i;
            break;
        }
    }

    if (first_fail_idx == -1) {
        cout << "YES\n";
        return;
    }

    int min_idx = 0;
    for (int i = 1; i <= first_fail_idx; i++) {
        if (a[i] < a[min_idx]) {
            min_idx = i;
        }
    }

    current_sum = 0;
    bool is_good = true;
    for (int i = 0; i < n; i++) {
        if (i == min_idx) continue; 

        current_sum += a[i];
        if (current_sum < 0) {
            is_good = false;
            break;
        }
    }

    if (is_good) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) 
    {
        solve();
    }
    return 0;
}
