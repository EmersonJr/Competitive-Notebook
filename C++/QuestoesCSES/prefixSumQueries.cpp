#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 
const int MAXN = 2e5 + 1;
const int INF = 1e18+1;
vector<int> v(MAXN, 0), t(4*MAXN), lazy(4*MAXN), aux(MAXN);
 
int merge(int x, int y){
 
    return max(x, y);
}
void prop(int id, int il, int ir){
 
    if(!lazy[id]) return;
 
    if(il != ir){
 
        lazy[2*id] += lazy[id];
        lazy[2*id+1] += lazy[id];
    }
 
    t[id] += lazy[id];
    lazy[id] = 0;
 
    return;
}
 
void build(int id, int il, int ir){
 
    if(il == ir){
 
        t[id] = v[il];
        return;
    }
 
    int im = (il + ir) >> 1;
 
    build(2*id, il, im);
    build(2*id+1, im+1, ir);
 
    t[id] = merge(t[2*id], t[2*id+1]);
 
    return;
}
 
void update(int id, int il, int ir, int l, int r, int x){
 
    prop(id, il, ir);
    if(l <= il && ir <= r){
 
        lazy[id] += x;
        prop(id, il, ir);
        return;
    }
    if(l > ir || il > r) return;
 
    int im = (ir+il) >> 1;
 
    update(2*id, il, im, l, r, x);
    update(2*id+1, im+1, ir, l, r, x);
 
    t[id] = merge(t[2*id+1], t[2*id]);
}
 
int query(int id, int il, int ir, int l, int r){
 
    prop(id, il, ir);
    if(l <= il && ir <= r) return t[id];
    if(l > ir || il > r) return -INF;
 
    int im = (ir+il) >> 1;
 
    int esq = query(2*id, il, im, l, r);
    int dir = query(2*id+1, im+1, ir, l, r);
 
    return merge(esq, dir);
}
 
int32_t main(){
    sws;
 
    int n, q; cin >> n >> q;
 
    for(int i = 1; i <= n; i++){
 
        cin >> aux[i];
 
        v[i] = v[i-1] + aux[i];
    }
 
    build(1, 0, n);
 
    while(q--){
 
        int t, l, r; cin >> t >> l >> r;
 
        if(t == 2){
 
            cout << query(1, 0, n, l-1, r) - query(1, 0, n, l-1, l-1) << '\n';
        } else {
 
            update(1, 0, n, l, n, r-aux[l]);
 
            aux[l] = r;
        }
    }
 
    return 0;
}