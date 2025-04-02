// acha a centroide, no da arvore em que nenhuma das subarvores de seus filhos possui tamanho maior que n/2
// usado na centroid decomposition, em que resolvemos o problema passando pela centroide e depois para cada subarvore por recursao
// achar a centroide => O(n)
// centroid decomposition => O(n*log(n))

vector<vector<int>> g;
vector<bool> inG;
vector<int> subtree_sz;

int find_centroid(int v) {
    int pai = 0;
    bool ok = false;

    while (!ok) {
        ok = true;

        for (int u : g[v]) {
            if (u == pai || !inG[u] || 2*subtree_sz[u] <= subtree_sz[v]) continue;

            subtree_sz[v] -= subtree_sz[u];
            subtree_sz[u] += subtree_sz[v];
            pai = v;
            v = u;
            ok = false;
            break;
        }
    }

    return v;
}