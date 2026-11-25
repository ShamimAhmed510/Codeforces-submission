#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define testcases int t; cin>>t;  while(t--)


void solve() {
    int n, m;
    cin >> n >> m;

    int ans = 0;
    int bestH = 0, bestV = 0, bestS = 0;

    for (int h = 0; h <= n; h++) {
        for (int v = 0; v <= m; v++) {

            int r = n - h - 2 * v;
            int c = m - 2 * h - v;

            if (r < 0 || c < 0)
                continue;

            int s = min(r, c);

            int k = 2 * h + 2 * v + s;

            if (k > ans) {
                ans = k;
                bestH = h;
                bestV = v;
                bestS = s;
            }
        }
    }

    vector<string> board(n, string(m, '.'));

    for (int i = 0; i < bestH; i++) {
        board[i][2 * i] = 'R';
        board[i][2 * i + 1] = 'R';
    }

    for (int i = 0; i < bestV; i++) {
        int row = bestH + 2 * i;
        int col = 2 * bestH + i;

        board[row][col] = 'R';
        board[row + 1][col] = 'R';
    }

    for (int i = 0; i < bestS; i++) {
        int row = bestH + 2 * bestV + i;
        int col = 2 * bestH + bestV + i;

        board[row][col] = 'R';
    }

    cout << ans << '\n';

    for (int i = 0; i < n; i++) {
        cout << board[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
