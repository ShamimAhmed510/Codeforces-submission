#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define yes cout << "YES"<<endl;
#define no cout <<"NO"<<endl;
#define testcase int t; cin>>t; while(t--)



int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        auto ask = [&](int u, int v, int d) {
            cout << "? " << u + 1 << " " << v + 1 << " " << d << endl;

            int ans;
            cin >> ans;

            return ans;
        };

        int v = 0;
        int dist = 0;

        for (int i = 1; i < N && dist < N - 1; i++) {

            if (ask(0, i, dist + 1) == 0)
                continue;

            v = i;
            dist++;

            while (dist < N - 1 &&
                   ask(0, i, dist + 1)) {
                dist++;
            }
        }

        int u = 0;

        for (int i = 0; i < N && dist < N - 1; i++) {

            if (i == v)
                continue;

            if (ask(v, i, dist + 1) == 0)
                continue;

            u = i;
            dist++;

            while (dist < N - 1 &&
                   ask(v, i, dist + 1)) {
                dist++;
            }
        }

  
        cout << "! " << u + 1 << " " << v + 1 << " " << dist << endl;
    }

    return 0;
} // https://codeforces.com/contest/2258/problem/C
