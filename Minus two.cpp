#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

void solve()
{
    int n, k;
    cin >> n ;
    // string s;
    // cin >> s;

    vector<int>v(n);

    for(int i=0; i<n; i++) cin>>v[i];

    int even = 0,odd=0;

    int a = 0,b = 0,x=0,y=0;
    int ans ;

    if(n == 2)
    {
        if(v[0]% 2 == v[1]%2)
            ans = 2;
    }
    else
    {

        for(int i=0; i<n; i++)
        {
            if(v[i] % 2 == 0)
            {
                even++;
                int k = v[i] / 2;
                if(k%2 == 0) a++;
                else b++;
            }
            else
            {
                odd++;
                int k = v[i] / 2;
                if(k%2 == 0) x++;
                else y++;
            }
        }

        int ans = max(a, max(b,max(x,y)));
    }

    cout << ans << endl;

}

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
