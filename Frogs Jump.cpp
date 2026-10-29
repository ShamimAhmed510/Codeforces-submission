#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        int top = 0, bottom = 0;
        int topPairs = 0, bottomPairs = 0;

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 'f') top++;
            if (b[i] == 'f') bottom++;
        }

        for (int i = 0; i + 1 < n; )
        {
            if (a[i] == 'f' && a[i + 1] == 'f')
            {
                topPairs++;
                i += 2;
            }
            else
            {
                i++;
            }
        }

        for (int i = 0; i + 1 < n; )
        {
            if (b[i] == 'f' && b[i + 1] == 'f')
            {
                bottomPairs++;
                i += 2;
            }
            else
            {
                i++;
            }
        }

        int diff = top - bottom;

        if (diff > 2 * topPairs)
        {
            cout << diff - 2 * topPairs << '\n';
        }
        else if (diff < -2 * bottomPairs)
        {
            cout << -diff - 2 * bottomPairs << '\n';
        }
        else
        {
            cout << abs(diff) % 2 << '\n';
        }
    }
    return 0;
}
