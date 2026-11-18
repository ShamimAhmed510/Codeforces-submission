
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    vector<string> s(n);

    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

   
    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for(int k = 0; k < n - 2; k++)
    {
        if(s[k + 2][k] == '1')
        {
            adj[k].push_back(k + 1);
            indegree[k + 1]++;
        }
        else
        {
            adj[k + 1].push_back(k);
            indegree[k]++;
        }
    }

   
    queue<int> q;

    for(int i = 0; i < n - 1; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }

    vector<int> order;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        order.push_back(u);

        for(int v : adj[u])
        {
            indegree[v]--;

            if(indegree[v] == 0)
            {
                q.push(v);
            }
        }
    }

    if(order.size() != n - 1)
    {
        cout << "NO\n";
        return;
    }

    vector<int> pos(n);

    for(int i = 0; i < n - 1; i++)
    {
        pos[order[i]] = i;
    }

    for(int i = 0; i < n; i++)
    {
        bool ok = true;

        for(int j = i - 1; j >= 0; j--)
        {
            if(j < i - 1)
            {
                if(pos[j] >= pos[j + 1])
                {
                    ok = false;
                }
            }

            if(s[i][j] != (ok ? '1' : '0'))
            {
                cout << "NO\n";
                return;
            }
        }

        ok = true;

        for(int j = i + 1; j < n; j++)
        {
            if(j > i + 1)
            {
                if(pos[j - 1] >= pos[j - 2])
                {
                    ok = false;
                }
            }

            if(s[i][j] != (ok ? '1' : '0'))
            {
                cout << "NO\n";
                return;
            }
        }

        if(s[i][i] != '1')
        {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    for(int i = 0; i < n - 1; i++)
    {
        cout << order[i] + 1 << " ";
    }

    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        solve();
    }

    return 0;
}
