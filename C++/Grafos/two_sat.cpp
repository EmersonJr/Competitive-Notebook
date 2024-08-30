#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define pb push_back
#define endl "\n"
#define input(x) for (auto &it : x) cin >> it;
#define output(x) for (auto &it : x) cout << it << ' ';
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ff first
#define ss second
 const int INF = 0x3f3f3f3f3f;
const long double PI = acos(-1);
const int MAX = 1004;
// SAT (Boolean satisfiability problem) is the problem of assigning Boolean values to variables to satisfy a given Boolean formula. The Boolean formula will usually be given in CNF (conjunctive normal form), which is a conjunction of multiple clauses, where each clause is a disjunction of literals (variables or negation of variables).
// 2-SAT (2-satisfiability) is a restriction of the SAT problem, in 2-SAT every clause has exactly two literals.
// $a, b, c$  such that the following formula is true:
//  
// $$(a \lor \lnot b) \land (\lnot a \lor b) \land (\lnot a \lor \lnot b) \land (a \lor \lnot c)$$ 

// SAT is NP-complete, there is no known efficient solution for it. However 2SAT can be solved efficiently in  
// $O(n + m)$  where  $n$  is the number of variables and  $m$  is the number of clauses.
int n;
int componente[MAX];
vector<int> adj[MAX];
vector<int> adj2[MAX];
vector<int> saida;
int vis[MAX];
bool ans[MAX];

void dfs(int u)
{
    vis[u] = 1;
    for(auto v : adj[u])
    {
        if(!vis[v])
        {
            dfs(v);
        }
    }
    saida.pb(u);
}

void dfs2(int u, int c)
{
    vis[u] = 2;
    componente[u] = c;
    for(auto v : adj2[u])
    {
        if(vis[v] == 1) dfs2(v, c);
    }
}
void add(int a, bool na, int b, bool nb)
{
    a = 2*(abs(a)-1) ^ na;
    b = 2*(abs(b)-1) ^ nb;
    int neg_a = a ^ 1;
    int neg_b = b ^ 1;
    adj[neg_a].pb(b);
    adj2[b].pb(neg_a);

}
bool possible()
{
    for(int i = 0; i < n; i++)
    {
        if(componente[2*i] == componente[2*i+1]) return false;
        ans[i] = componente[2*i + 1] < componente[2*i];
    }
    return true;
}
void solve()
{
    cin >> n;
    vector<vector<int>> m(3, vector<int>(n));
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            m[i][j] = x;
        }
    }
   
   for(int i = 0; i < n; i++)
   {
        add(m[0][i], m[0][i] > 0, m[1][i], m[1][i] > 0);
        add(m[0][i], m[0][i] > 0, m[2][i], m[2][i] > 0);

        add(m[1][i], m[1][i] > 0, m[0][i], m[0][i] > 0);
        add(m[1][i], m[1][i] > 0, m[2][i], m[2][i] > 0);

        add(m[2][i], m[2][i] > 0, m[0][i], m[0][i] > 0);
        add(m[2][i], m[2][i] > 0, m[1][i], m[1][i] > 0);
   }

    // for(int i = 0; i < 2*n +2; i++)
    // {
    //     cout << i << ": ";
    //     for(auto x : adj[i])
    //     {
    //         cout << x << " ";
    //     }
    //     cout << endl;
    // }
    //  return;

    for(int i = 0; i < 2*n; i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }

    int c = 0;
    for(int i = saida.size() - 1; i >= 0; i--)
    {
        if(vis[saida[i]] == 1)
        {
            c++;
            dfs2(saida[i], c);
        }
    }
    
    bool resp = possible();
    
    cout << (resp? "YES\n" : "NO\n");

    return;
}
int32_t main()
{   sws

    int t;
    //t = 1;
    cin >> t;

    while(t--)
    {
        memset(vis,0,sizeof(vis));
        memset(componente, 0 , sizeof(componente));
        for(int i = 0; i < MAX; i++)adj[i].clear();
        for(int i = 0; i < MAX; i++)adj2[i].clear();
        saida.clear();
        solve();
    }
    return 0;
}