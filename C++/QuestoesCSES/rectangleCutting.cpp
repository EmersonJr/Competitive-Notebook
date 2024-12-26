#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
typedef pair<int, int> ii;
#define INF INT64_MAX
const int MAX = 5e3+1;
 
vector<vector<int>> memo(MAX, vector<int> (MAX, -1));
int l, c;
 
int dp(int x, int y){
 
    if(x == y) return 0;
 
    if(memo[x][y] != -1) return memo[x][y];
    
    int aux = INF, aux1 = -INF, aux2 = -INF;
    
    for(int i = 1; i <= x/2 ; i++){
        
        aux1 = dp(i, y) + dp(x-i, y)+1;
        aux = min(aux, aux1);
    }
    
    for(int i = 1; i <= y/2 ; i++){
        
        aux2 = dp(x, i) + dp(x, y-i)+1;
        aux = min(aux, aux2);
    }
    
    return memo[x][y] = aux;
}
int32_t main(){
    sws;
 
    cin >> l >> c;
 
    int ans = dp(l, c);
    cout << ans << '\n';
    return 0;
}