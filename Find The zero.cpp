#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define testcase int t;cin>>t;while(t--)
#define ll long long
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
//https://codeforces.com/problemset/problem/2209/C


int main()
{
    optimize();

    testcase
    {
        int n;
        cin >> n;

        int ans = -1;

        for (int i = 1; i < n; i++)
        {
            cout << "? " << 2 * i + 1 << " " << 2 * i + 2 << endl;
            cout.flush();

            int x;
            cin >> x;

            if (x)
            {
                ans = 2 * i + 1;
                break;
            }
        }

        if (ans == -1)
        {
            cout << "? 1 3" << endl;
            cout.flush();

            int x;
            cin >> x;

            if (x)
            {
                ans = 1;
            }
            else
            {
                cout << "? 1 4" << endl;
                cout.flush();

                cin >> x;

                if (x)
                {
                    ans = 1;
                }
                else
                {
                    ans = 2;
                }
            }
        }

        cout << "! " << ans << endl;
        cout.flush();
    }

    return 0;
}
