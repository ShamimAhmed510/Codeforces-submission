#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int odd = 0, even = 0;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;

            if (x % 2 == 0)
                even++;
            else
                odd++;
        }

        if ((odd == 3 && even == 0) ||
            (odd == 1 && even == 1)) {
            cout << "Larpity\n";
        } else {
            cout << "Moggity\n";
        }
    }

    return 0;
}
