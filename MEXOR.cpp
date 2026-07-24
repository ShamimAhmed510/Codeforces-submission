#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
// https://codeforces.com/contest/2245/problem/C
void solve()
{
    long long n, k;
    cin >> n >> k;

    if (n == 1)
    {
        if (k == 1)
        {
            cout << "YES\n0\n";
        }
        else
        {
            cout << "NO\n";
        }
        return;
    }

    k ^= n;

    int k_len = (k == 0) ? 0 : 64 - __builtin_clzll(k);
    int n_len = (n - 1 == 0) ? 0 : 64 - __builtin_clzll(n - 1);

    if (k_len > n_len)
    {
        cout << "NO\n";
        return;
    }

    vector<long long> s;
    if (0 < k && k <= n - 1)
    {
        s.push_back(k);
    }
    else if (k > 0)
    {
        s.push_back(n - 1);
        s.push_back((n - 1) ^ k);
    }
    s.push_back(0);

    unordered_set<long long> in_s(s.begin(), s.end());

    vector<long long> a = s;
    for (long long i = 0; i < n; i++)
    {
        if (in_s.find(i) == in_s.end())
        {
            a.push_back(i);
        }
    }

    cout << "YES\n";
    for (int i = (int)a.size() - 1; i >= 0; i--)
    {
        cout << a[i] << (i == 0 ? "" : " ");
    }
    cout << "\n";
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
