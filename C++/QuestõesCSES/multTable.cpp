#include <bits/stdc++.h>
using namespace std;
    
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long
#define endl "\n"
#define pb push_back
#define all(x) x.begin(), x.end()
    
typedef long long ll;
typedef long double ld;    
const ll MOD = 1e9+7;
const int MAX = 1e6+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const int LOG = 21;
    
int k, n;
 
bool check(int x){
 
    int aux = 0;
 
    for(int i = 1; i <= n; i++){
 
        aux += min(n, x / i);
    }
 
    return (aux < k);    
}
 
void solve(){
 
    cin >> n;
 
    k = (n*n+1)/2;
 
    int l = 1, r = n*n, ans = 0;
 
    while(l <= r){
 
        int mid = (l+r) / 2;
 
        if(check(mid)){
 
            l = mid+1;
        } else{
 
            ans = mid;
            r = mid-1;
        }
    }
    
    cout << ans << '\n';
    return;
}
int32_t main(){ 
    sws;
 
     int t = 1; 
    //  cin >> t;
 
    while(t--)
        solve();
    
    return 0;
}   