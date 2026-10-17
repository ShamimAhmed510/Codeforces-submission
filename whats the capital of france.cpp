#include <bits/stdc++.h>
using namespace std; 

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    long long mx = 0;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]); 
    }

    if (n == 1) {
        cout << mx << "\n";
        return;
    }

    long long k = 0;
    while ((1LL << (k + 1)) <= mx) {
        k++;
    }

    long long ans = (1LL << (k + 1)) - 1;
    cout << ans << "\n";
}

int main() {
    int t; cin>>t;
    while(t--)
    {
      solve();
    }
    return 0;
}
