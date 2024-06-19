#include <bits/stdc++.h>
 
using namespace std;
#define int long long
const int MOD = 1e9+7;
 
const int MAX = 2e5+1;
 
vector<int> segt(8*MAX), euler(2*MAX), in(MAX), out(MAX), aux(MAX);
int tempo = 0;
vector<int> t[MAX];
 
void dfs(int u, int p){
 
    euler[tempo] = u;
    in[u] = tempo;
 
    tempo++;
 
    for(auto v : t[u]){
 
        if(v != p) dfs(v, u);
    }
 
    euler[tempo] = u;
    out[u] = tempo;
 
    tempo++;
    
    return;
}
 
void build(int id, int il, int ir){
 
    if(il == ir){
 
        segt[id] = aux[euler[il]];
        return;
    }
 
    int im = (il + ir) / 2;
 
    build(2*id, il, im);
    build(2*id+1, im+1, ir);
 
 
    segt[id] = segt[2*id] + segt[2*id+1];
}
 
void update(int id, int il, int ir, int idx, int x){
 
    if(il == ir){
 
        segt[id] = x;
        aux[euler[idx]] = x;
        return;
    }
 
    int im = (il + ir) / 2;
 
    if(im < idx){
 
        update(2*id+1, im+1, ir, idx, x);  
    } else {
 
        update(2*id, il, im, idx, x);
    }
 
    segt[id] = segt[2*id] + segt[2*id+1];
 
    return;
}
 
int query(int id, int il, int ir, int l, int r){
 
    if(il >= l && ir <= r){
 
        return segt[id];
    }
    if(l > ir || r < il) return 0;
 
    int im = (il + ir) / 2;
 
    int esq = query(2*id, il, im, l, r);
    int dir = query(2*id+1, im+1, ir, l, r);
 
    return esq + dir;
}
 
int32_t main(){
 
    int n, q; cin >> n >> q;
 
    for(int i = 1; i <= n; i++) cin >> aux[i];
 
    for(int i = 2; i <= n; i++){
 
        int u, v; cin >> u >> v;
 
        t[u].push_back(v);
        t[v].push_back(u);
    }
 
    dfs(1, 0);
 
    build(1, 0, 2*(n));
 
    while(q--){
 
        int t; cin >> t;
 
        if(t == 1){
 
            int v, p; cin >> p >> v;
 
            update(1, 0, 2*(n), in[p], v);
            update(1, 0, 2*(n), out[p], v);
        } else {
 
            int p; cin >> p;
 
            cout << query(1, 0, 2*(n), in[p], out[p]) / 2 << '\n';
        }
    }
 
    return 0;
}
