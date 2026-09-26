#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define testcases int t; cin>>t; while(t--)
#define yes  cout<"YES"<<endl;
#define no  cout<"NO"<<endl;
#define frloop(n) for(int i=0; i<n; i++) 

int main() 
{
  optimize();
  
  testcases
  {
    
   int n;
   char c;
   cin>>n>>c;

  string s; cin>>s;

   int cnt  =0 ;

 for (int i = 0; i < n/2; i++) 
   {
        if (s[i] != s[n - 1 - i])
        {
          if(s[i] == c || s[n - 1 - i] == c)
          {
            cnt++;
          }else 
          {
            cnt+=2;
          }
        }
    }

    cout << cnt << endl;
   
   
    
  }
    return 0 ;
}
