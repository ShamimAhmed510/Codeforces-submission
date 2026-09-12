// https://codeforces.com/contest/2260/problem/E

#include <bits/stdc++.h>
using namespace std;

int minimumGroup(int same00, int same11, int diff)
{
    int low = (same00 + same11 + diff) / 4;
    int high = 100000000;
    int ans = high;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        int break00 = max(0, same00 - mid);
        int break11 = max(0, same11 - mid);

        int needMixed = break00 + break11;

        if (needMixed + diff / 2 <= mid)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<int> one(n + 1, 0);
    vector<int> change(n, 0);

    for (int i = 0; i < n; i++)
        one[i + 1] = one[i] + (s[i] == '1');

    for (int i = 0; i + 1 < n; i++)
        change[i + 1] = change[i] + (s[i] != s[i + 1]);

    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if (l == r)
        {
            cout << 3 << '\n';
            continue;
        }

        int ones = one[r] - one[l - 1];
        int len = r - l + 1;
        int zeros = len - ones;

        int diff = change[r - 1] - change[l - 1];
        if (s[l - 1] != s[r - 1])
            diff++;

        int pair00 = zeros - diff / 2;
        int pair11 = ones - diff / 2;

        int each = minimumGroup(pair00, pair11, diff);

        cout << each * 4 - len << '\n';
    }
}
