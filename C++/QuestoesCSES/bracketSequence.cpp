#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define esp  ' '
#define int long long int
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second
#define sws ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
const string YES = "YES";
const string NO = "NO";
const int MAX= 2e6+5;
const int MOD= 1e9+7;
const int INF = 0x3f3f3f3f3f3f3f3f;
int fat[MAX], C[MAX];
 
int fexp(int b, int e){
    if (e==0) return 1;
 
    int ans = fexp(b, e/2);
    if(e%2) return (((ans*ans)%MOD)*b)%MOD;
    else return (ans*ans)%MOD;
}
 
void fluminense(){
    int  n; cin >> n;
    int ans = 0;
    if(n%2==1) ans=0;
    else{
        n = n>>1;
        ans = C[n];
    }
    
    cout << ans <<endl; 
 
 
}
 
int32_t main(){
    sws;    
    fat[0]=1;
    for(int i=1; i<MAX; i++) fat[i] = (i*fat[i-1])%MOD;
    for(int i=0; i<(MAX>>1)-1; i++){
        C[i] = ((((fat[2*i]*(fexp(fat[i], MOD-2)%MOD))%MOD*(fexp(fat[i], MOD-2)%MOD)))%MOD)*(fexp(i+1, MOD-2)%MOD);
        C[i]%=MOD;
    }
 
 
    int T=1;
    //cin >> T;
    while(T--)fluminense(); 
    
}