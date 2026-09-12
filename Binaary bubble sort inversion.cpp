#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/2259/problem/F
int main() {
    int t;
    cin >> t;

    while (t--) {

        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        string s;
        cin >> s;

        long long inv = 0;

        int one = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == 1)
                one++;
            else
                inv += one;
        }

        cout << inv << " ";

        deque<int> d;
        for (int x : a)
            d.push_back(x);

        int zero = 0;
        for (int x : a)
            if (x == 0)
                zero++;

        for (int i = 0; i < n; i++) {

            while (!d.empty() && d.front() == 0) {
                d.pop_front();
                zero--;
            }

            while (!d.empty() && d.back() == 1) {
                d.pop_back();
            }

            if (d.empty()) {
                cout << 0 << " ";
                continue;
            }

            if (s[i] == '1') {
                inv -= zero;
                d.pop_front();
            }
            else {
                int oneInside = d.size() - zero;
                inv -= oneInside;
                d.pop_back();
                zero--;
            }

            cout << inv << " ";
        }

        cout << "\n";
    }
}
