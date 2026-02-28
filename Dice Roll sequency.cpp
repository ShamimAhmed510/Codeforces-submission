#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define testcase int t; cin>>t; while(t--)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define minusone cout<<"-1"<<endl;

//https://codeforces.com/contest/2195/problem/C

int main()
{
    optimize();

    testcase
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0; i<n; i++)
        {
            cin>>v[i];
        }

        bool ok = false ;

        int ans = 0;
        for (int i = 1; i < n; i++)
        {
            if (v[i] + v[i-1] == 7 or v[i] == v[i-1]) ans++, i++;
        }

        cout << ans << endl;


    }

    return 0 ;
}

