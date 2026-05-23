// In the name of Allah, the Most Gracious, the Most Merciful.

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define tst int t;cin>>t;while(t--)
#define pb push_back
#define vc vector
#define vi vc<int>
#define vl vc<ll>
#define mp(x,y) make_pair(x,y)
#define yes cout<<"YES"<<'\n';
#define no cout<<"NO"<<'\n';
#define srt(v) sort(v.begin(),v.end());
#define rsrt(v) sort(v.rbegin(),v.rend());
#define rvs(v) reverse(v.begin(),v.end());
#define F first
#define S second
#define MOD 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define PI 2*acos(0.0)
#define pii pair<int,int>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define coutv(v) for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v) for(auto &it:v)cin>>it;
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ld long double
#define nl '\n'
// https://codeforces.com/contest/2230/problem/D

int main()
{
    optimize();

    tst
    {
        int n;
        cin >> n;

        vector<int> a(n), b(n);

        for (auto &x : a)
        {
            cin >> x;
            --x;
        }

        for (auto &x : b)
        {
            cin >> x;
            --x;
        }

        vector<int> p1(n + 1, n);
        vector<int> p2(n + 1, n);
        vector<int> dp(n + 1, n);

        long long ans = 0;

        for (int i = n - 1; i >= 0; i--)
        {

            p1[a[i]] = i;
            p2[b[i]] = i;

            if (a[i] == b[i])
            {

                int nx = a[i] + 1;

                if (p1[nx] == p2[nx])
                {
                    dp[i] = dp[p1[nx]];
                }
                else
                {
                    dp[i] = min(p1[nx], p2[nx]);
                }
            }

            if (p1[0] != p2[0])
            {
                ans += min(p1[0], p2[0]) - i;
            }
            else
            {
                ans += dp[p1[0]] - i;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
