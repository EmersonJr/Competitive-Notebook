#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long int
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);
typedef pair<int, int> ii;
#define INF INT64_MAX
const int MAX = 5e3+1;
 
vector<vector<int>> memo(MAX, vector<int> (MAX, -1));
string s, t;
 
int dp(int i, int j){
 
    if(i == -1) return j+1;
    if(j == -1) return i+1;
 
    if(memo[i][j] != -1) return memo[i][j];
 
    int ins = dp(i-1, j) + 1;
    int del = dp(i, j-1) + 1;
    int mod = dp(i-1, j-1) + (s[i] != t[j]);
 
    int aux = min(del, mod);
    return memo[i][j] = min(ins, aux);
}
int32_t main(){
    sws;
 
    cin >> s >> t;
 
    cout << dp(s.size()-1, t.size()-1) << '\n';
    return 0;
}