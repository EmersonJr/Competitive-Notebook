#include <bits/stdc++.h>
using namespace std;

// codigo de Range Minimum query; Spt = sparse table.
// You are given an array  $A[1..N]$ . You have to answer incoming queries of the form
//  $(L, R)$ , which ask to find the minimum element in array  $A$  between positions  $L$  and  $R$  inclusive.+
// SPARSE TABLE ---->
// Sparse Table is a data structure, that allows answering range queries. It can answer most range queries in  
// $O(\log n)$ , but its true power 
// is answering range minimum queries (or equivalent range maximum queries). 
// For those queries it can compute the answer in  $O(1)$  time.

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

    int n; cin >> n;

    int aux = n, log = 0;

    while(aux / 2){

        log++;
        aux /= 2;
    }

    vector<vector<int>> spt(n, vector<int> (log+1));
    vector<int> v(n);

    for(int i = 0; i < n; i++) {cin >> v[i]; spt[i][0] = v[i];}

    for(int j = 1; j < log+1; j++){
        for(int i = 0; i + (1 << j) -1 < n; i++){

            spt[i][j] = min(spt[i][j-1], spt[i + (1 << j-1)][j-1]);
        }
    }

    int q; cin >> q;

    while(q--){

        int l, r; cin >> l >> r;

        aux = r-l+1; log = 0;
        
        while(aux / 2){log++; aux /= 2;}

        cout << min(spt[l][log], spt[r - (1 << log) + 1][log]) << '\n';
    }
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