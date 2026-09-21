#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define testcase int t; cin>>t; while(t--)
#define yes cout << "YES"<<endl;
#define no cout << "NO"<<endl;


int main() 
{
    optimize();

    testcase 
    {
       int n, a1, a2, a3;
        cin >> n;
        cin >> a1 >> a2 >> a3;

        cout << n - min({a1, a2, a3}) << "\n";
    }
    return 0;
} 
//https://codeforces.com/contest/2266/problem/A
