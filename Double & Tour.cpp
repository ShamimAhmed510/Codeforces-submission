
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0);

int main()
{
    optimize();

    int t;
    cin >> t;

    while(t--)
    {
        int n;
        cin >> n;

        vector<ll> v(n);

        ll sum = 0;
        ll mx = 0;

        for(int i = 0; i < n; i++)
        {
            cin >> v[i];

            sum += v[i];
            mx = max(mx, v[i]);
        }

        ll ans = 0;

        for(int i = 0; i < n; i++)
        {
            ll newSum = sum + v[i];
            ll newMx = max(mx, 2LL * v[i]);

            ll score = newSum - newMx;

            ans = max(ans, score);
        }

        cout << ans << endl;
    }

    return 0;
}
