//https://codeforces.com/contest/2250/problem/B
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tst int t; cin >> t; while(t--)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;


void solve() {
    int n, k;
    cin >> n >> k;

    if (k == n - 1) {
        cout << -1 << "\n";
        return;
    }

    int target_zeros = (n + 1) / 2;
    int target_ones = n / 2;

    int L = n - k;

    int base_zeros = 0, base_ones = 0;
    for (int i = 0; i < L; i++) {
        if (i % 2 == 0) base_zeros++;
        else base_ones++;
    }

    int extra_zeros = target_zeros - base_zeros;
    int extra_ones = target_ones - base_ones;

    string ans = "";
    bool first_zero_done = false;
    bool first_one_done = false;

    for (int i = 0; i < L; i++) {
        if (i % 2 == 0) { 
            if (!first_zero_done) {
                ans.append(1 + extra_zeros, '0'); 
                first_zero_done = true;
            } else {
                ans += '0';
            }
        } else { 
            if (!first_one_done) {
                ans.append(1 + extra_ones, '1'); 
                first_one_done = true;
            } else {
                ans += '1';
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
