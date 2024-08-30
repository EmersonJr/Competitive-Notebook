#include <bits/stdc++.h>
using namespace std;
// We are given an undirected graph. An articulation point (or cut vertex) is defined as a vertex which, 
// when removed along with associated edges, makes the graph disconnected 
// (or more precisely, increases the number of connected components in the graph).
// The task is to find all articulation points in the given graph.
// The algorithm described here is based on depth first search and has  
// $O(N+M)$  complexity, where  $N$  is the number of vertices and  $M$  is the number of edges in the graph.
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define int long long
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int MAXN = 1e5+1;
const int INF = INT32_MAX;
const int MOD = 998244353;
const int LOG = 18;

vector<bool> vis(MAXN);
vector<vector<int>> g(MAXN);
vector<int> tin(MAXN, -1), low(MAXN, -1);
int t = 0;
set<int> ans;

void AP(int u, int p = -1){

    int qtdfilhos = 0;
    low[u] = tin[u] = t++;
    vis[u] = true;

    for(auto v: g[u]){

        if(v == p) continue;

        if(!vis[v]){

            qtdfilhos++;

            AP(v, u);

            low[u] = min(low[u], low[v]);

            if(low[v] >= tin[u] && u != 1) ans.insert(u);
        } else{

            low[u] = min(low[u], tin[v]);
        }
    }

    if(u == 1 && qtdfilhos >= 2) ans.insert(u);
}
void solve(){

    int n, m; cin >> n >> m;

    for(int i = 0; i < m; i++){

        int u, v; cin >> u >> v;

        g[u].pb(v);
        g[v].pb(u);
    }

    AP(1);

    cout << ans.size() << '\n';

    for(auto x : ans) cout << x << ' ';

    cout << '\n';

    return;
}
int32_t main(){ 
    sws;
    int t = 1;
    // cin >> t;

    while(t--)
        solve();

    return 0;
}