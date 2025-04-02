// Heavy-Light Decompostion
// ordena o euler tour de forma que fazer queries no caminho de um no ate a raiz fica O(log(n) * (complexidade da query em range))

struct HLD {
    int n;
    vector<vector<int>> g;
    vector<int> sz, ordem, head, idx, parent;
    SegTree seg;

    HLD(int n, vector<vector<int>> &g): n(n), g(g), sz(n+1), idx(n+1), head(n+1), parent(n+1) {
        subtree_sz(1, -1, 0);
        build(1, 1, -1);

        seg = SegTree(ordem.size(), ordem);
    }

    void update(int v, int x) {
        seg.update(idx[v], x);
    }

    int query(int u) {
        int ans = -INF;

        int anc = 1;        // colocando ate a raiz como exemplo, poderia ser ate o lca tbm
        while (head[u] != head[anc]) {
            ans = max(ans, seg.query(idx[head[u]], idx[u]));
            u = parent[head[u]];
        }
        ans = max(ans, seg.query(idx[anc], idx[u]));

        return ans;
    }
    
    int subtree_sz(int v, int pai, int d) {
        int sub = 1;
        parent[v] = pai;

        for (auto u : g[v]) {
            if (u == pai) continue;

            sub += subtree_sz(u, v, d+1);
        }

        return sz[v] = sub;
    }

    void build(int v, int h, int pai) {
        int mai = -1, to = -1;
        head[v] = h;
        idx[v] = ordem.size();
        ordem.pb(val[v]);

        for (auto u : g[v]) {
            if (u == pai) continue;

            if (sz[u] > mai) {
                mai = sz[u];
                to = u;
            }
        }

        if (to != -1) build(to, h, v);
        for (auto u : g[v]) {
            if (u == to || u == pai) continue;

            build(u, u, v);
        }
    }
};