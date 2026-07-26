//https://codeforces.com/contest/2250/problem/A 
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define tst int t; cin >> t; while(t--)
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

int main() 
{
    optimize();
    tst
    {
        int n;
        cin >> n;
        vector<int> v(n);

        for(int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        if (n % 2 != 0) {
            no
            continue;
        }

        int minodd = INT_MAX;
        int maxeven = 0;
 
        for(int i = 0; i < n; i += 2)
        {
            minodd = min(minodd, v[i]);
        }

        for(int i = 1; i < n; i += 2)
        {
            maxeven = max(maxeven, v[i]);
        }

        if(minodd - maxeven >= 2) yes
        else no
    }
 
    return 0;
}
