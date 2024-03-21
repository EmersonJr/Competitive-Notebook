vector<int> v(MAXN), t(4*MAXN), lazy(4*MAXN);
 
int merge(int x, int y){
 
    return x + y;
}
void prop(int id, int il, int ir){
 
    if(!lazy[id]) return;
 
    if(il != ir){
 
        lazy[2*id] += lazy[id];
        lazy[2*id+1] += lazy[id];
    }
 
    t[id] += (ir - il + 1) * lazy[id];
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
    if(l > ir || il > r) return 0;
 
    int im = (ir+il) >> 1;
 
    int esq = query(2*id, il, im, l, r);
    int dir = query(2*id+1, im+1, ir, l, r);
 
    return merge(esq, dir);
}
