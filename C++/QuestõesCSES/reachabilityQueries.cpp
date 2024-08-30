#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
typedef pair<int, int> ii;
#define INF INT64_MAX
const int MAX = 5e4+1;
const int MOD = 1e9+7;
    
vector<int> g[MAX], ginv[MAX], gscc[MAX];
vector<int> scc(MAX);
vector<bool> vis(MAX), visscc(MAX);
vector<bitset<MAX>> ans(MAX);
 
stack<int> s;
 
void topo(int u){
 
    vis[u] = true;
 
    for(int v : g[u]) if(!vis[v]) topo(v);
 
    s.push(u);
 
    return;
}
 
void gsscc(int u, int c){
 
    scc[u] = c;
 
    for(auto v : ginv[u]){
 
        if(!scc[v]) gsscc(v, c);
        else gscc[scc[v]].push_back(scc[u]);
    }    
}
 
bitset<MAX> dfs(int u){
 
    visscc[u] = true;
    ans[u].set(u);
 
    for(auto v : gscc[u]){
 
        if(!visscc[v]) dfs(v);
 
        ans[u] |= ans[v];
    }
 
    return ans[u];
}
int32_t main(){
    sws;
 
    int n, m, q; cin >> n >> m >> q;
 
    for(int i = 0; i < m; i++){
 
        int u, v; cin >> u >> v;
 
        g[u].push_back(v);
        ginv[v].push_back(u);
    }
 
    int comp = 1;
 
    for(int i = 1; i <= n; i++)
        if(!vis[i]) topo(i);
 
    while(!s.empty()){
        int u;
        tie(u) = s.top(); s.pop();
 
        if(!scc[u]){
 
            // cout << comp << '\n';
            gsscc(u, comp);
            comp++;            
        }
    }
 
    for(int i = 1; i <= n; i++)
        if(!visscc[i]) dfs(i);
 
    while(q--){
 
        int u, v; cin >> u >> v;
 
        if(ans[scc[u]][scc[v]]) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}