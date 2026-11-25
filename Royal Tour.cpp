#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define testcases int t; cin>>t;  while(t--)


ll dist(ll r1, ll c1, ll r2, ll c2)
{
    return max(abs(r1-r2), abs(c1-c2));
}

int main()
{
    optimize();

    testcases
    {
        ll n, m, r, c;
        
        cin >> n >> m;
        cin >> r >> c;

        vector<pair<ll,ll>> corner = {
            {1, 1},
            {1, m},
            {n, 1},
            {n, m}
        };

        vector<int> p = {0, 1, 2, 3};

        ll ans = LLONG_MAX;

        do
        {
            ll sum = 0;

            sum += dist(r, c,
                        corner[p[0]].first,
                        corner[p[0]].second);

            for(int i = 0; i < 3; i++)
            {
                sum += dist(
                    corner[p[i]].first,
                    corner[p[i]].second,
                    corner[p[i+1]].first,
                    corner[p[i+1]].second
                );
            }

            ans = min(ans, sum);

        } while(next_permutation(p.begin(), p.end()));

        cout << ans << '\n';
    }

    return 0;
}
