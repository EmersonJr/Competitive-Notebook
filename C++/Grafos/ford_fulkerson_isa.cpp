#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pb push_back

// Description: 
// Obtains the maximum possible flow rate given a network. A network is a graph with a single source vertex and a single sink vertex in which each edge has a capacity

// Complexity:
// O(V * E^2) where V is the number of vertex and E is the number of edges
const int MAXN = 501;
const int MAXE = 1001;
const int INF = INT64_MAX;

// represents the capacities of the edges
int capacity[MAXN][MAXE];
// represents the graph and it may contain negative edges
vector<int> adj[MAXN];
int n, e;


int bfs(int s, int t, vector<int>& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int next : adj[cur])
        {
            //cout << "cur next " << cur << ' ' << next <<  ' ' << parent[next] << ' ' << capacity[cur][next] << endl; 
            if (parent[next] == -1 && capacity[cur][next])
            {
                parent[next] = cur;
                int new_flow = min(flow, capacity[cur][next]);
                if (next == t)
                {
                    //cout << new_flow << endl;
                    return new_flow;
                }
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

int maxflow(int s, int t) {
    int flow = 0;
    vector<int> parent(n+1);
    int new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int32_t main()
{
    cin>>n>>e;
    int s = 1, t = n;
    //cin>>s>>t;

    for(int i = 0; i < e; i++)
    {
        int from, to, cap;
        cin>>from>>to>>cap;

        capacity[from][to] += cap;
        adj[from].push_back(to);
        //adding the negative edges
        adj[to].push_back(from);
    }

    // for(int i = 1; i <= n; i++)
    // {   cout << i << " : ";
    //     for(auto x : graph[i]) cout << x << ' ';
    //     cout << endl;
    // }

    int maxFlow = maxflow(s, t);

    cout<<maxFlow<<endl;

    return 0;
}