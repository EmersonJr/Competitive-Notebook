// Trie + KMP

struct Aho {
    public:
        int n;
        vector<vector<int>> adj, nxt;
        vector<int> lnk, lnkt;
        vector<int> terms;
 
        Aho(): n(1) {
            adj.emplace_back(26, -1);
            terms.pb(0);
        }
 
        int add_str(string &s) {
            int cur = 0;
            for (char c : s) {
                int& prox = adj[cur][c-'a'];
 
                if (prox == -1) {
                    prox = n;
                    cur = n;
 
                    adj.emplace_back(26, -1);
                    terms.pb(0);
                    n++;
                } else
                    cur = prox;
            }
 
            terms[cur]++;
            return cur;
        }
 
        void build() {
            int v, prox;
            lnkt.assign(n, 0);
            lnk.assign(n, 0);
            nxt.assign(n, vector<int>(26, 0));
 
            queue<int> q;
            q.push(0);
            while (!q.empty()) {
                v = q.front();
                q.pop();
 
                rep(i, 0, 26) {
                    prox = adj[v][i];
                    if (prox != -1) {
                        lnk[prox] = v ? nxt[lnk[v]][i] : 0;
                        lnkt[prox] = terms[lnk[prox]] ? lnk[prox] : lnkt[lnk[prox]];
                        q.push(prox);
                        nxt[v][i] = prox;
                    } else
                        nxt[v][i] = nxt[lnk[v]][i];
                }
            }
        }
};