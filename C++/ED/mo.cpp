//Distinct values queries
#include <bits/stdc++.h>
 
using namespace std;
//#define int long long
#define pii pair<int,int>
#define ll long long
#define vi vector<int>
#define pb push_back
#define endl "\n"
#define input(x) for (auto &it : x) cin >> it;
#define output(x) for (auto &it : x) cout << it << ' ';
#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ff first
#define ss second
 
const long double PI = acos(-1);
int atual = 1;
int freq[200002];
struct Q
{
    int l,r, idx, block;
    Q(int p1, int p2, int i, int b)
    {
        l = p1;
        r = p2;
        idx = i;
        block = l/b;
    }
    bool operator < (Q& query2)
    {
        if(block == query2.block) return r < query2.r;
        return block < query2.block;
    }
 
};
 
void add(int x)
{
    if(!freq[x])
    {
        atual++;
    }
    freq[x]++;
}
void rem(int x)
{
    freq[x]--;
    if(!freq[x])
    {
        atual--;   
    }
}
void solve()
{
    int n,q;
    cin >> n >> q;
    int b = sqrt(q) + 1;
    b = n/b + 1;
    vector <int> v(n);
    map<int,int> compress;
    vector<Q> queries;
    int aux = 1;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if(compress.count(x))
        {
            v[i] = compress[x];
        }
        else
        {
            compress[x] = aux;
            v[i] = aux;
            aux++;
        }
    }
 
    for(int i = 0; i < q; i++)
    {
        int x,y;
        cin >> x >> y;
        queries.pb(Q(x-1,y-1,i,b));
    }
 
    sort(queries.begin(), queries.end());
    vi ans(q,0);
    int curl = 0, curr = 0;
    freq[v[0]]++;
    
    for(auto query : queries)
    {
        //cout << query.l << ' ' << query.r << '\n';
        while(curl > query.l)
        {
            curl--;
            add(v[curl]);
        }
        while(curr < query.r)
        {
            curr++;
            add(v[curr]);
        }
        while(curl < query.l)
        {
            rem(v[curl]);
            curl++;
        }
        while(curr > query.r)
        {
            rem(v[curr]);
            curr--;
        }
        ans[query.idx] = atual;
    }
    
    for(auto resp : ans) cout << resp << '\n';
 
    
    return;
}
int32_t main()
{   sws
    int t = 1;
    while (t--)
    {
        solve();
    }
    
    return 0;
}