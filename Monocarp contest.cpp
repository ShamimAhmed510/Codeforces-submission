#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/contest/2260/problem/A 
#define ll long long 
#define testcases int t; cin>>t; while(t--)
#define endl '\n'
#define optimize() ios::sync_with_stdio(false); cin.tie(nullptr);
#define forlp(n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vll vector<ll>
#define yes cout << "YES"<<endl;
#define no cout<<"NO"<<endl;


int main()
 { 
    optimize()

    testcases
    {
        int n; cin>>n;

        vector<int>v(n);

        int cnt = 0;

       for(int i=0; i<n; i++) {
        cin>>v[i];
        if(v[i] == 0) cnt++;
       }

    //    for(int i=0; i<n; i++) cout<<v[i];

    if(v[0] == 0 && v[n-1] == 0) 
    {
        cout << 0 << endl;
    }
    else if(cnt <= 1)
    {
      cout << -1 << endl;
    }
    else if(v[0] == 0 || v[n-1] == 0)
    {
         cout << 1 << endl;
    }
    else 
    {
        cout << 2 << endl;
    }

    }

    return 0;
}
