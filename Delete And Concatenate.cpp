#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/2245/problem/B
void solve()
{
    int n, c;
    cin >> n >> c;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        a[i] -= c;
    }

    for (int i = 0; i < n / 2; i++)
    {
        a[i] = max(a[i], 0);
    }

    long long total_sum = accumulate(a.begin(), a.end(), 0LL);
    cout << total_sum << "\n";
}

int main()
{
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
