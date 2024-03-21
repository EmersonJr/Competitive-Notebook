#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
typedef pair<int, int> ii;
#define INF INT64_MAX
const int MAX = 2e5+1;
const int MOD = 1e9+7;
const int LOG = 30;

vector<bool> vis;
vector<int> tin, low, comp;
vector<vector<int>> g(MAX), bt(MAX);
map<pair<int, int>, bool> ponteh;
int time = 0;

void buildBt(int u, int c){

    comp[u] = c;
    vis[u] = true;

    for(auto v : g[u]){

        if(vis[v] || ponteh[{u, v}]) continue;

        buildBt(v, c);
    }
}

void findBridge(int u, int p = -1){

    vis[u] = true;
    tin[u] = low[u] = time++;

    for(auto v : g[u]){

        if(v == p) continue;

        if(vis[v]){

            low[u] = min(low[u], tin[u]);
        } else{

            dfs(v, u);
            low[u] = min(low[u], low[v]);

            if(low[v] > tin[u])
                éPonte(u, v);
        }
    }
}

int32_t main(){
    sws;

    for(auto[u, v]: ponteh){

        if(v){

            bt[comp[u.ff]].pb(comp[u.ss]);
            bt[comp[u.ss]].pb(comp[u.ff]);
        }
    }
    return 0;
}