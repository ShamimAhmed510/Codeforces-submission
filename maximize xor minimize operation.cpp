https://codeforces.com/contest/2260/problem/C
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define testcases int t; cin>>t; while(t--)
#define endl '\n'
#define optimize() ios::sync_with_stdio(false); cin.tie(nullptr);
#define forlp(n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vll vector<ll>
#define yes cout << "YES"<<endl;
#define no cout<<"NO"<<endl;

const ll INF = (1LL << 60);

ll dp[31][2][2];
ll bestA[31][2][2];
bool vis[31][2][2];

int x, y;
int S;

pair<ll, ll> dfs(int pos, int carry, int borrow) {
    if (pos == 30) {
        if (carry == 0 && borrow == 0) return {0, 0};
        return {INF, -1};
    }

    if (vis[pos][carry][borrow])
        return {dp[pos][carry][borrow], bestA[pos][carry][borrow]};

    vis[pos][carry][borrow] = true;

    ll mnAnd = INF;
    ll mxA = -1;

    int sBit = (S >> pos) & 1;
    int xBit = (x >> pos) & 1;

    for (int aBit = 0; aBit <= 1; aBit++) {
        for (int bBit = 0; bBit <= 1; bBit++) {
            int sum = aBit + bBit + carry;
            if ((sum & 1) != sBit) continue;

            int nextCarry = sum >> 1;

            int val = xBit - aBit - borrow;
            int nextBorrow = (val < 0);

            auto nxt = dfs(pos + 1, nextCarry, nextBorrow);
            if (nxt.first == INF) continue;

            ll curAnd = nxt.first + (1LL * (aBit & bBit) << pos);
            ll curA = nxt.second + (1LL * aBit << pos);

            if (curAnd < mnAnd || (curAnd == mnAnd && curA > mxA)) {
                mnAnd = curAnd;
                mxA = curA;
            }
        }
    }

    dp[pos][carry][borrow] = mnAnd;
    bestA[pos][carry][borrow] = mxA;

    return {mnAnd, mxA};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int qrTNum;
    cin >> qrTNum;

    while (qrTNum--) {
        cin >> x >> y;
        S = x + y;

        memset(vis, 0, sizeof(vis));

        auto res = dfs(0, 0, 0);

        ll maxXor = 1LL * S - 2LL * res.first;
        ll operations = 1LL * x - res.second;

        cout << maxXor << " " << operations << "\n";
    }

    return 0;
}
