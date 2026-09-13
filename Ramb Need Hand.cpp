#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define endl '\n'
#define optimize() ios::sync_with_stdio(false); cin.tie(nullptr);
#define testcase int t; cin>>t; while(t--)
#define yes cout << "YES"<<endl;
#define no cout << "NO" << endl;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];

        vector<int> pos;
        vector<int> vis(n + 1, 0);
        bool ok = true;

        for (int i = 1; i <= n; i++) {
            if (p[i] != i) {
                if (p[p[i]] != i) {
                    ok = false;
                    break;
                }
                if (!vis[i]) {
                    vis[i] = vis[p[i]] = 1;
                    pos.push_back(min(i, p[i]));
                    pos.push_back(max(i, p[i]));
                }
            }
        }

        if (!ok) {
            cout << "NO\n";
            continue;
        }

        sort(pos.begin(), pos.end());

        int m = pos.size();
        for (int i = 0; i < m; i++) {
            if (p[pos[i]] != pos[m - 1 - i]) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
} // https://codeforces.com/contest/2264/problem/A
