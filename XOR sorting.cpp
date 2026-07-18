#include <bits/stdc++.h>
using namespace std;
#define ll long long
//https://codeforces.com/contest/2247/problem/D1
#define optimize() ios_base::sync_with_stdio(false); cin.tie(NULL);

#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

#define test int t; cin >> t; while (t--)
#define endl '\n'

#define vi vector<int>
#define vll vector<ll>

#define pb push_back
#define lp(i,n) for(int i=0; i<n; i++)

#define srt(v) sort(v.begin(),v.end());
#define srtr(v) sort(v.rbegin(),v.rend());

#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a * b) / gcd(a, b))



void solve()
{
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    stable_sort(a.begin(), a.end(), [](const pair<int, int>& x, const pair<int, int>& y)
    {
        return x.first < y.first;
    });

    int max_diff = 0;
    for (int i = 0; i < n; i++)
    {
        max_diff = max(max_diff, a[i].second ^ i);
    }

    if (max_diff == 0)
    {
        cout << 0 << "\n";
    }
    else
    {
        int p = 1;
        while (p <= max_diff)
        {
            p <<= 1;
        }
        cout << (p >> 1) << "\n";
    }
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
