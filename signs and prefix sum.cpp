// https://codeforces.com/contest/2260/problem/D 
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define testcases int t; cin>>t; while(t--)
#define endl '\n'
#define optimize() ios::sync_with_stdio(false); cin.tie(nullptr);
#define forlp(n) for(int i=0; i<n; i++)
#define vi vector<int>
#define vll vector<ll>
#define yes cout << "YES"<<endl;
#define no cout<<"NO"<<endl;



bool isValid(const string& str, int max_diff) {
    int current_states = (1 << 3);

    for (char ch : str) {
        int next_states = 0;

        for (int curr = -3; curr <= 3; ++curr) {
            if (!(current_states & (1 << (curr + 3)))) continue;

            for (int nxt = -3; nxt <= 3; ++nxt) {
                if (curr == nxt || abs(curr - nxt) > max_diff) continue;

                bool matches = (ch == '0' && nxt == 0) ||
                               (ch == '+' && nxt > 0) ||
                               (ch == '-' && nxt < 0);

                if (matches) {
                    next_states |= (1 << (nxt + 3));
                }
            }
        }

        current_states = next_states;
        if (current_states == 0) return false;
    }

    return current_states > 0;
}

void solve() {
    int length;
    string seq;
    cin >> length >> seq;

    if (seq.empty() || seq[0] == '0' || seq.find("00") != string::npos) {
        cout << -1 << '\n';
        return;
    }

    for (int k = 1; k <= 3; ++k) {
        if (isValid(seq, k)) {
            cout << k << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    if (cin >> test_cases) {
        while (test_cases--) {
            solve();
        }
    }

    return 0;
}
