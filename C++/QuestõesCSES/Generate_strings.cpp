#include <bits/stdc++.h>
using namespace std;

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl "\n"
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int MAXN = 1e7+1;
const int INF = INT64_MAX;
const int MOD = 1e9+7;

void solve(){
    
    int n, x, y; cin >> n >> x >> y;
    
    vector<int> dp(2*(n+1), INF);

    dp[0] = 0;

    for(int i = 1; i <= n; i++){

        dp[i] = min(dp[i-1]+x, dp[i]);
        if(!(i%2)) dp[i] = min(dp[i / 2]+y, dp[i]);
        else dp[i] = min(dp[(i+1)/2]+x+y, dp[i]);   
    }
    cout << dp[n] << '\n';

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