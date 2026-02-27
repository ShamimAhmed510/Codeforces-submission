#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define testcase int t; cin>>t; while(t--)
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define minusone cout<<"-1"<<endl;



int main()
{
    optimize();

    testcase
    {
        int n;
        cin>>n;
        vector<int>v(n+1);

        for(int i=1; i<=n; i++)
        {
            cin>>v[i];
        }

        for(int i=1; i<=n; i+=2)
        {
            for(int j=i; j<=n; j*=2)
            {
                for(int k=i*2; k<=n; k*=2)
                {
                    if(v[k/2]>v[k])swap(v[k/2],v[k]);
                }
            }
        }
        if(is_sorted(begin(v),end(v)))cout<<"YES\n";
        else cout<<"NO\n";
        }
    return 0 ;
}
