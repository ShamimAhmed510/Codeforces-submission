#include <bits/stdc++.h>
using namespace std;

bool solve(long long k, vector<long long>& a, int x)
{
    int n = a.size();
    vector<int> isolated;
    for (int i = 0; i < n; i++)
    {
        bool connected = false;

        if (i > 0 && a[i] - a[i - 1] <= k)
            connected = true;

        if (i + 1 < n && a[i + 1] - a[i] <= k)
            connected = true;

        if (!connected)
            isolated.push_back(i);
    }

    int extra = isolated.size();
    for (int i = 0; i + 1 < (int)isolated.size();)
    {
        int u = isolated[i];
        int v = isolated[i + 1];

        if (v == u + 1 && a[v] - a[u] <= 2 * k)
        {
            extra--;
            i += 2;
        }
        else
        {
            i++;
        }
    }

    return extra <= x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<long long> a(n);

        for (int i = 0; i < n; i++)
            cin >> a[i];
        long long low = 1;
        long long high = a[n - 1] - a[0];
        while (low < high)
        {
            long long mid = low + (high - low) / 2;

            if (solve(mid, a, x))
                high = mid;
            else
                low = mid + 1;
        }
        cout << low << '\n';
    }
    return 0;
}
