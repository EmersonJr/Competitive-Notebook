#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
typedef pair<int, int> ii;
#define INF INT64_MAX
const int MAX = 2e5+1;
const int MOD = 1e9+7;
const int LOG = 30;
 
int ances[MAX][LOG];
int depth[MAX];
 
int get_lca(int no, int no1){
 
    int k;
 
    if (depth[no1] > depth[no]) swap(no, no1);
 
    k = depth[no] - depth[no1];
 
    for(int i = LOG-1; i >= 0; i--){
    
        if(k & (1 << i)){
 
            no = ances[no][i];
        }
    }
 
    if(no == no1) return no;
 
    for(int i = LOG-1; i >= 0; i--){
        
        if(ances[no][i] != ances[no1][i]){
    
            no = ances[no][i];
            no1 = ances[no1][i];
        }
    }
    return ances[no][0];
 
}
int32_t main(){
    sws;
 
    int n, q; cin >> n >> q;
 
    vector<int> parents(n+1);
 
    for(int i = 2; i <= n; i++){
 
        int v; cin >> v;
 
        parents[i] = v;
    }
 
    for(int j = 1; j < LOG; j++){
 
        for(int i = 1; i <= n; i++){
 
            ances[i][0] = parents[i];
 
            if(i != 1) depth[i] = depth[parents[i]] + 1;
 
            ances[i][j] = ances[ances[i][j-1]][j-1];
        }
    }
 
    while(q--){
 
        int no, no1; cin >> no >> no1;
 
        int ans = get_lca(no, no1);
 
        cout << ans << '\n';
    }
 
    return 0;
}