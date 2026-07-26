//https://codeforces.com/contest/2250/problem/C
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

        vector<int> l(n), r(n), u(n), v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> l[i] >> r[i] >> u[i] >> v[i];
        }

        int max_len = 0;

        for (int m = n; m >= 1; m--)
        {
            int j = 1; 
            for (int i = 0; i < n; i++)
            {
                int left_rank = j;
                int right_rank = m - j + 1;
                bool valid_left = (left_rank < l[i] || left_rank > r[i]);
                bool valid_right = (right_rank < u[i] || right_rank > v[i]);

                if (valid_left && valid_right)
                {
                    j++; 
                    if (j > m) break; 
                }
            }

            if (j > m)
            {
                max_len = m;
                break; 
            }
        }

        cout << max_len << "\n";
    }
    return 0;
}
