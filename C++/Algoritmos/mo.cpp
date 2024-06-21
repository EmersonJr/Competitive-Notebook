#include <bits/stdc++.h>
using namespace std;
 
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define ld long double
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int MAXN = 101;
const int INF = INT64_MAX;
const int MOD = 1e9+7;
const int LOG = 60;
const ld PI = acos(-1);
 
struct QueryMo{
 
    int l, r, sec, ord;
 
    QueryMo(int inL, int inR, int inSec, int inOrd){
 
        l = inL, r = inR, sec = inL / inSec, ord = inOrd;
    }
 
    bool operator<(QueryMo &compa){
 
        return make_pair(sec, r) < make_pair(compa.sec, compa.r);
    }
 
};
void solve(){
 
    int n, q; cin >> n >> q;
 
    vi v(n);
    map<int, int> id;
 
    for(int i = 0; i < n; i++){
 
        int x; cin >> x;
 
        if(!id.count(x)) id[x] = i+1;
 
        v[i] = id[x];
    }
 
    vector<QueryMo> auxQueries;
 
    int rt = min((int)200, (int)(sqrt(q)));
 
    for(int i = 0; i < q; i++){
 
        int l, r; cin >> l >> r;
 
        QueryMo aux = QueryMo(--l, --r, rt, i);
 
        auxQueries.pb(aux);
    }
 
    vi resp(q);
 
    sort(all(auxQueries));
 
    int actL = 0, actR = 0, ans = 0;
    vector<int> freqs(2e5+2, 0);
 
    ans++;
    freqs[v[actL]]++;
 
    for(auto query : auxQueries){
 
        while(actR < query.r){
 
            actR++;
            if(!freqs[v[actR]]) ans++;
            freqs[v[actR]]++;
        }
 
        while(actL > query.l){
 
            actL--;
            if(!freqs[v[actL]]) ans++;
            freqs[v[actL]]++;
        }
            
        while(actL < query.l){
 
            freqs[v[actL]]--;
            if(!freqs[v[actL]]) ans--;
            actL++;
        }
 
        while(actR > query.r){
 
            freqs[v[actR]]--;
            if(!freqs[v[actR]]) ans--;
            actR--;
        }
        
 
        resp[query.ord] = ans; 
    }
 
    for(int i = 0; i < q; i++) cout << resp[i] << '\n';
 
    return;
}
int32_t main(){ 
    sws;
 
    int t = 1;
    // cin >> t;
 
    while(t--)
        solve();
 
    return 0;
}