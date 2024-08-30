#include <bits/stdc++.h>
 
 // Calcula distancias com arestas negativas
//  Serve pra achar ciclo também
// Vetor de distancias da pripri
using namespace std;
#define int long long
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
const int MAXN = 2e5 + 1;
const int INF = 1e18+1;
 
vector<int> d(MAXN, -INF), points(MAXN, -1);
vector<bool> vis(MAXN);
vector<vector<int>> g(MAXN);
int n;
 
struct edge{
 
    int x, y, c; 
};
 
vector<edge> edges;
void bf(int u){
 
    d[u] = 0;
 
    for(int i = 0; i < n - 1; i++){
 
        for(auto e : edges){
 
            if(d[e.x] > -INF){
                if(d[e.y] < d[e.x] + e.c){
 
                    d[e.y] = d[e.x] + e.c;
                }
            }
        }
    }
}
 
int dfs(int u){
 
    if(u == n) return points[u] = 1;
 
    vis[u] = true;
 
    int aux = -1;
    for(auto v : g[u]){
 
        if(!vis[v]) aux = dfs(v);
    }
 
    return points[u] = aux;
}
 
bool find(){
 
   for(int i = 0; i <= n - 1; i++){
 
        for(auto e : edges){
 
                if(d[e.y] < d[e.x] + e.c){
 
                    if(points[e.y] == 1) return true;
                    d[e.y] = d[e.x] + e.c;
                }
        }
    }
 
    return false;
}
 
 
int32_t main(){
    sws;
 
    int m; cin >> n >> m;
 
    for(int i = 0; i < m; i++){
 
        edge e; cin >> e.x >> e.y >> e.c;
 
        g[e.x].push_back(e.y);
        edges.push_back(e);
    }
 
    bf(1);
    dfs(1);
    if(find()){cout << -1 << '\n'; return 0;}
 
    cout << d[n] << '\n';
    return 0;
}