#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcase int t;cin>>t;while(t--)
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
// https://codeforces.com/contest/2216/problem/B

void solve()
{
    long long t, h, u;
    cin >> t >> h >> u;

    if (t > h * 2 + u)
    {
        cout << (t * 2 + h * 3 + u * 2 + 1) << "\n";
    }
    else
    {
        cout << (t * 2 + h * 3 + u * 3 - min(t, u)) << "\n";
    }
}

int main()
{
    optimize();

    testcase
    {
        solve();
    }
    return 0;
}
