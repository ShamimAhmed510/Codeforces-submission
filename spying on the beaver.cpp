#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long 
#define optimize()ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define testcase int t; cin>>t; while(t--)


void solve() 
{
    int n;
    cin >> n;

    vector<int> parent_node(n + 1, 0);
    vector<int> depth(n + 1, 0);

    for (int i = 2; i <= n; i++) 
    {
        cin >> parent_node[i];
        depth[i] = depth[parent_node[i]] + 1;
    }

    int m;
    cin >> m;

    vector<int> dams(m);
    vector<bool> has_dam(n + 1, false);

    for (int i = 0; i < m; i++) {
        cin >> dams[i];
        has_dam[dams[i]] = true;
    }

    if (m == 1) 
    {
        cout << 0 << "\n";
        return;
    }

    vector<int> result_nodes;

    if (has_dam[1]) 
    {
        for (int d : dams) 
        {
            if (d != 1)
            {
                result_nodes.push_back(d);
            }
        }
    } 
    else {
        int skipped_dam = dams[0];
        for (int d : dams) 
        {
            if (depth[d] < depth[skipped_dam])
           {
                skipped_dam = d;
            }
        }

        for (int d : dams) 
        {
            if (d != skipped_dam) 
            {
                result_nodes.push_back(d);
            }
        }
    }

    cout << result_nodes.size();
    for (int u : result_nodes) {
        cout << " " << u;
    }
    cout << "\n";
}

int main() 
{
    optimize();

    testcase 
    {
        solve();
    }
    return 0;
}
