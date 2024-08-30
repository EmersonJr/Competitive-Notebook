#include <bits/stdc++.h>
using namespace std;

// permite que você saiba se um número 
// faz parte de alguma lis
// calcula pra direita e pra esquerda
// Instead of the above method for computing the longest increasing subsequence in  

// $O(n \log n)$  we can also solve the problem in a different way: using some simple data structures.

// Let's go back to the first method. Remember that  
// $d[i]$  is the value  $d[j] + 1$  with  $j < i$  and  

// $a[j] < a[i]$ .

// Thus if we define an additional array  

// $t[]$  such that
//  
// $$t[a[i]] = d[i],$$ 

// then the problem of computing the value  
// $d[i]$  is equivalent to finding the maximum value in a prefix of the array  

// $t[]$ :
//  
// $$d[i] = \max\left(t[0 \dots a[i] - 1] + 1\right)$$ 

// The problem of finding the maximum of a prefix of an array (which changes) is a 
// standard problem that can be solved by many different data structures. For instance we can use a Segment tree or a Fenwick tree.

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int long long int
#define float long double
#define ld long double
#define ll long long
#define pb push_back
#define ff first
#define ss second
#define vi vector<int>
#define vpii vector<pair<int, int>> 
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define in(v) for(auto & x : v) cin >> x;
// #define out(v) for(auto x : v) cout << x << ' ';
#define tfii tuple<float, int, int>

const int MAXN = 4e5+1;
const int INF = INT32_MAX;
const int MOD = 1e9+7;
const int LOG = 31;
const ld PI = acos(-1);
const int MINF = INT64_MIN;
vpii dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// vc é bom basta calma
// rating is just a number
// leia a questão inteira e com calma
// não olhe os standings
// esqueça o tempo
// é só mais um virtual
// se divirta
// AAAAAAAAAAAAAAAAAAAAAAAAAAAA

class SegTree{
    int n, elem_neutro = 0;
    vector<int> tree, lazy, v;

    int merge(int a, int b){
        return max(a, b); //seg de soma
    }

    void build(int l, int r, int no){
        if(l==r){
            tree[no] = v[l];
            return;
        }
        int mid = (l+r)/2;
        build(l, mid, 2*no);
        build(mid+1, r, 2*no+1);
    
        tree[no] = merge(tree[2*no], tree[2*no+1]);
    }

    void update(int A, int B, int x, int l, int r, int no){
        prop(l, r, no);
        if(B<l or r<A) return;
        if(A<=l and r<=B){
            lazy[no] = x; //update de soma
            prop(l, r, no);
            return;
        }
        int mid = (l+r)/2;
    
        update(A, B, x, l, mid, 2*no);
        update(A, B, x, mid+1, r, 2*no+1);
        
        tree[no] = merge(tree[2*no], tree[2*no+1]);
    }

    void prop(int l, int r, int no){
        if(lazy[no]!=0){
            tree[no] = lazy[no]; //update de soma
            if(l!=r){
                lazy[2*no] = lazy[no]; //update de soma
                lazy[2*no+1] = lazy[no]; //update de soma
            }
            lazy[no] = 0;
        }
    }

    int query(int A, int B, int l, int r, int no){
        prop(l, r, no);
        if(B<l or r<A) return elem_neutro;
        if(A<=l and r<=B) return tree[no];
        int mid = (l+r)/2;
    
        return merge(query(A, B, l, mid, 2*no),
                    query(A, B, mid+1, r, 2*no+1));
    }

    public:
        SegTree(vector<int> &v){
                this->n=v.size();
                this->v=v;
                tree.assign(4*n, 0);
                lazy.assign(4*n, 0);
                build(0, n-1, 1);
            }
        int query(int l, int r){return query(l, r, 0, n-1, 1);}
        void update(int l, int r, int val){update(l, r, val, 0, n-1, 1);}
        void out(){for(int i=0; i<n; i++){cout<<query(i, i)<<" ";cout<<endl;}}
};


void solve(){

    int n, last = 1; cin >> n;

    map<int, int> compr;

    vi ord(n);
    set<int> s;

    for(int i = 0; i < n; i++){

        cin >> ord[i];

        s.insert(ord[i]);
    }

    for(auto x : s){

        compr[x] = last;

        last++;
    }

    vi v(last+1, 0), dp(n);

    SegTree left(v), right(v);

    for(int i = 0; i < n; i++){

        int aux = left.query(0, compr[ord[i]]-1);
        
        dp[i] += aux;
        left.update(compr[ord[i]], compr[ord[i]], aux+1);
    }

    for(int i = n-1; i > -1; i--){

        int aux = right.query(compr[ord[i]]+1, last);
        dp[i] += aux;
        right.update(compr[ord[i]], compr[ord[i]], aux+1);
    }

    set<int> ans;

    int lis = right.query(0, last);

    for(int i = 0; i < n; i++){

        if(lis == (dp[i] + 1)) ans.insert(i+1);
    }

    cout << ans.size() << '\n';

    for(auto x : ans) cout << x << ' ';

    cout << '\n';

    return;
}
int32_t main(){ 
    sws;

    int t = 1;
    cin >> t;

    while(t--)
        solve();

    return 0;
}   