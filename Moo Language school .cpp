#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

void solve()
{
    int n, k;
    cin >> n ;
    string s;
    cin >> s;

    int total_nhoj_land_used = 0;
    int num_farms = n / k;

    for (int i = 0; i < num_farms; ++i)
    {
        bool has_free_field = false;

        for (int j = 0; j < k; ++j)
        {
            if (s[i * k + j] == '0')
            {
                has_free_field = true;
                break;
            }
        }

        if (!has_free_field)
        {
            total_nhoj_land_used++;
        }
    }

    cout << total_nhoj_land_used << "\n";
}

int main()
{
    // Fast I/O
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
