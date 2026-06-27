#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/problemset/problem/2227/D

int n;
vector<int> a;

int solve(int l, int r) {
    set<int> st;

    for (int i = 0; i <= n; i++)
        st.insert(i);

    while (l >= 0 && r < 2 * n && a[l] == a[r]) {
        st.erase(a[l]);   
        l--;
        r++;
    }

    return *st.begin();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) 
    {
        cin >> n;
        a.assign(2 * n, 0);

        for (int i = 0; i < 2 * n; i++)
            cin >> a[i];

        int firstZero = -1, secondZero = -1;

        for (int i = 0; i < 2 * n; i++) {
            if (a[i] == 0) {
                if (firstZero == -1)
                    firstZero = i;
                else
                    secondZero = i;
            }
        }

        cout << max({
            solve(firstZero, firstZero),                    
            solve(secondZero, secondZero),                  
            solve((firstZero + secondZero) / 2,
                  (firstZero + secondZero + 1) / 2)         
        }) << '\n';
    }
}
