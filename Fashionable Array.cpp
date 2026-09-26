#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long 
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define testcases int t; cin>>t; while(t--)
#define yes  cout<"YES"<<endl;
#define no  cout<"NO"<<endl;
#define frloop(n) for(int i=0; i<n; i++) 

void solve() {
    int n;
    cin >> n;
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        freq[x]++;
    }

    vector<int> result;
    
    vector<pair<int, int>> elements; 
    for (auto it = freq.rbegin(); it != freq.rend(); ++it) {
        elements.push_back({it->first, it->second});
    }

    while (result.size() < (size_t)n) {
        bool added = false;
        for (auto& p : elements) {
            if (p.second > 0) {
                result.push_back(p.first);
                p.second--;
                added = true;
            }
        }
        if (!added) break;
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
