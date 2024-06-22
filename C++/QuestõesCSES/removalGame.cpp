#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
typedef pair<int, int> ii;
#define INF INT64_MAX
const int MAX = 5e3+1;
 
int memo[MAX][MAX][2];
vector<int> v(MAX);
 
int dp(int l, int r, bool w){
 
    if(l > r) return 0;
    if(memo[l][r][w] != -1) return memo[l][r][w];
    
    if(w){
 
        int aux = dp(l+1, r, !w);
        int aux1 = dp(l, r-1, !w);
        return memo[l][r][w] = min(aux, aux1);
    } else{
 
        int aux = dp(l+1, r, !w) + v[l];
        int aux1 = dp(l, r-1, !w) + v[r];
        return memo[l][r][w] = max(aux, aux1);
    }
}
int32_t main(){
    sws;
 
    int n; cin >> n;
    
    memset(memo, -1, sizeof(memo));
    for(int i = 0; i < n; i++) cin >> v[i];
 
    cout << dp(0, n-1, 0) << '\n';
 
    return 0;
}