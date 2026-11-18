#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long N, M;
    int K;
    
    if (!(cin >> N >> M >> K)) return;

    vector<pair<long long, long long>> slow(K);
    
    for (int i = 0; i < K; ++i) 
    {
        cin >> slow[i].first >> slow[i].second;
    }

    sort(slow.begin(), slow.end());

    vector<long long> lis;
    
    for (int i = 0; i < K; ++i) 
    {
        long long y = slow[i].second;
        auto it = upper_bound(lis.begin(), lis.end(), y);
        if (it == lis.end()) 
        {
            lis.push_back(y);
        } 
        else {
            *it = y;
        }
    }

    long long ans = N + M - 1 + (long long)lis.size();
    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (cin >> T)
    {
        while (T--)
        {
            solve();
        }
    }
    return 0;
}
