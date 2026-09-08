#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/contest/2260/problem/B
#define ll long long 
#define testcases int t; cin>>t; while(t--)
#define endl '\n'
#define optimize() ios::sync_with_stdio(false); cin.tie(nullptr);
#define forlp(n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vll vector<ll>
#define yes cout << "YES"<<endl;
#define no cout<<"NO"<<endl;

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define testcases int t; cin>>t; while(t--)
#define endl '\n'
#define optimize() ios::sync_with_stdio(false); cin.tie(nullptr);

int main() { 
    optimize();

    testcases {
        ll x, y, k;
        cin >> x >> y >> k;

        ll ans = 0;
        ll diff = y - x;

        for (ll i = 0; i < k; i++) {
            ll curr_x = x + i;
            ll curr_y = y + i;
            
            if (curr_x > diff) {
                ll remaining_steps = k - i;
                ans += remaining_steps * diff;
                break;
            } else {
                ans += (curr_y % curr_x);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
