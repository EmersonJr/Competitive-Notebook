#include <bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
 
    string s; cin >> s;
 
    vector<char> c;
 
    for(int i = 0; i < s.size(); i++) c.push_back(s[i]);
 
    set<string> se;
    sort(c.begin(), c.end());
 
    string resp = "";
    for(int i = 0; i < s.size(); i++) resp += c[i];
 
    se.insert(resp);
 
    while(next_permutation(c.begin(), c.end())){
 
        string resp = "";
        for(int i = 0; i < s.size(); i++) resp += c[i];
 
        se.insert(resp);        
    }
 
    cout << se.size() << '\n';
 
    for(auto t: se) cout << t << '\n';
    return 0;
}