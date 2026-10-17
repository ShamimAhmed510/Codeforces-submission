#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t; cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string s;
         cin>>s;
         int f=0,l=0;
         for(int i=0; i<n; i++)
         {
            if(s[i] == '1'){
               f = i+1;
               break;
            }
         }

         for(int i=0; i<n; i++)
         {
            if(s[i] == '1'){
               l = i+1;
            //    break;
            }
         }
         cout << l- f<<endl;

    }
    return 0;
}
