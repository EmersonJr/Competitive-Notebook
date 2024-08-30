#include <bits/stdc++.h>
using namespace std;
// o problema tinha como objetivo encontrar quatro uplas alternadas
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl "\n"
#define ld long double
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
const int MAXN = 5e5+2;
const int INF = INT32_MAX;
const int MOD = 1e9+7;
const int LOG = 60;

vector<int> v(MAXN, INF);
vector<int> Ar(4*MAXN);
vector<int> best_4upla(MAXN, INF);
int n;

void build(int id, int il, int ir){ //Por ser uma arvore os filhos são tratados com 2*pai+1 ou somente 2*pai
// Os intervalos são tratados pela divisão na metade dos intervalos
    if(il == ir){ //Ent chegamos a um intervalo unico
 
        Ar[id] = v[il];
        return;
    }
 
    int im = (il + ir) / 2; // Traça-se o meio para definir o novo intervalo de construção
 
    build(2*id, il, im);
    build(2*id + 1, im + 1, ir);      //desce na arvore para definir o valor dos filhos
 
    Ar[id] = min(Ar[2*id], Ar[2*id+1]);     //define o nodo atual
 
    return;
}
 
int query(int l, int r, int id, int il, int ir){
 
    if(il >= l && ir <= r) return Ar[id];  //Esse il e ir se encontram dentro do meu alvo
    if(r < il || l > ir) return INF;      //Não se encontram
 
    int im = (ir + il) / 2;
 
    int esq = query(l, r, 2*id, il, im);
    int dir = query(l, r, 2*id+1, im+1, ir);
 
    return min(esq, dir);
}
 
void update(int idx, int x, int id, int il, int ir){
 
    if(il == ir){
 
        Ar[id] = x;
        v[idx] = x;
        return;
    }
 
    int im = (il + ir) / 2;
 
    if(im < idx){
 
        update(idx, x, 2*id+1, im + 1, ir);        
    } else{
 
        update(idx, x, 2*id, il, im);
    }
 
    Ar[id] = min(Ar[2*id + 1], Ar[2*id]);
 
    return; 
}

vector<int> memo(MAXN, -1);

int dp(int x){

    if(x > n) return memo[x] = 0;
    if(memo[x] != -1) return memo[x];

    int aux = 0;

    aux = max(aux, dp(x+1));
    if(best_4upla[x] != INF) aux = max(aux, dp(best_4upla[x]+1)+1);
    
    return memo[x] = aux;
}

void solve(){

    build(1, 1, MAXN-1);
    
    cin >> n;

    vector<int> nums(n+2), ante(n+2, -1), poste(n+2, -1);
    
    map<int, vector<int>> ids;
    
    set<int> aux;
    
    map<int, int> last;

    for(int i = 1; i <= n; i++){

        int x; cin >> x;
        nums[i] = x;
        if(last.count(x)){

            ante[i] = last[x];
            poste[last[x]] = i;
        }
        
        aux.insert(x);
        ids[x].pb(i);
        
        last[x] = i;
    }
    
    
    for(auto i : aux){
        
        for(int j = 0; j + 3 < (int)(ids[i].size()); j++){
            
            best_4upla[ids[i][j]] = ids[i][j+3];
        }
    }
    
    for(int i = n; i > 0; i--){

        if(ante[i] == -1) continue;

        best_4upla[ante[i]] = min(best_4upla[ante[i]], query(ante[i]+1, i-1, 1, 1, MAXN-1));
        
        update(ante[i], i, 1, 1, MAXN-1);
    }

    int ans = dp(1);
    
    cout << 4*ans << '\n';

    vector<int> idxs;
    
    int i = 1;
    while(i <= n && ans){
        if(best_4upla[i] != INF && memo[best_4upla[i]+1] == ans-1){
    
            idxs.pb(i);
            idxs.pb(best_4upla[i]);
            ans--;
            i = best_4upla[i]+1;
            
        } else if(memo[i+1] == ans){
            
            i++;
        }
    }
    
    for(int i = 0; i < (int)(idxs.size())-1; i+=2){
        
        cout << nums[idxs[i]] << ' ' << nums[idxs[i+1]] << ' ' << nums[idxs[i]] << ' ' << nums[idxs[i+1]] << ' ';
    }

    cout << '\n';
    
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