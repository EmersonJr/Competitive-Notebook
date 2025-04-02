vector<int> adj[MAX];
const int LOG = 30;
int up[MAX][LOG], parent[MAX];
 
void process(int n){
    for(int v=1; v<=n; v++){
        up[v][0]= parent[v];
        for(int i=1; i<LOG; i++){
            up[v][i] = up[ up[v][i-1] ][i-1];
        }
    }
}
 
int jump(int n, int k){
    for(int i=0; i<LOG; i++){
		if(k & (1 << i)){
			n = up[n][i];
		}
	}
	if(n == 0) return -1;
	return n;
}
    		
int32_t main(){
    
    int n, q; cin>>n>>q;
    
    parent[1] = 0;
    for(int i=1; i<=n-1; i++){
        int x;
        cin>>x;
        parent[i+1] = x;
        
        adj[i+1].pb(x);
        adj[x].pb(i+1);
    }
    process(n);
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        
        cout<<(jump(a,b))<<endl;
    }
}

// binary lifting pra achar o max no caminho entre duas arestas

vector<vector<pii>> g;
vector<int> depth(MAX);
vector<pii> pai;
int p2k[MAX][LOG], bin_max[MAX][LOG];

int preprocess(int u, int p, int d) {
    depth[u] = d;

    for (auto [v, c] : g[u]) {
        if (v == p) continue;

        pai[v] = {u, c};
        preprocess(v, u, d+1);
    }
}

int max_cam(int u, int v) {
    int ans = -INF;
    if (depth[u] < depth[v]) swap(u, v);

    for (int i = LOG-1 ; i >= 0 ; i--) {
        if (depth[p2k[u][i]] >= depth[v]) {
            ans = max(ans, bin_max[u][i]);
            u = p2k[u][i];
        }
    }

    if (u == v) return ans;

    for (int i = LOG-1 ; i >= 0 ; i--) {
        if (p2k[v][i] != p2k[u][i]) {
            ans = max(ans, bin_max[v][i]);
            ans = max(ans, bin_max[u][i]);
 
            v = p2k[v][i];
            u = p2k[u][i];
        }
    }

    ans = max(ans, max(bin_max[u][0], bin_max[v][0]));
    return ans;
}

void solve() {
    // ...

    preprocess(1, 0, 0);
    rep(no, 1, n+1) {
        p2k[no][0] = pai[no].ff;
        bin_max[no][0] = pai[no].ss;
    }

    rep(i, 1, LOG) {
        rep(no, 1, n+1) {
            p2k[no][i] = p2k[p2k[no][i-1]][i-1];
            bin_max[no][i] = max(bin_max[no][i-1], bin_max[p2k[no][i-1]][i-1]);
        }
    }

    // ...
}