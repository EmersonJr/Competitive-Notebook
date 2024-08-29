//The prefix function is a string matching technique used in computer science and string algorithms. 
//It efficiently computes an array that represents the length of the longest proper prefix which is also a suffix 
//for each prefix of a given string. The Knuth-Morris-Pratt (KMP) algorithm utilizes the prefix function to 
//perform pattern matching in linear time, making it an efficient algorithm for searching 
//occurrences of a pattern within a text.

// O(n+m)

#include <bits/stdc++.h>
 
using namespace std;
const int MAX = 1e6+1;
string p;
vector<int> nbr(MAX);
 
int nxt(char c, int n){
 
    while(n != -1){
        if((n+1) < p.size() && p[n + 1] == c){
            
            n++;
            break;
        } else {
 
            n = nbr[n];
        }
    }
 
    if(n == -1 && p[0] == c) n++;
 
    return n;
}
void kmp(){
 
    int n = p.size();
 
    nbr[0] = -1;
 
    for(int i = 1; i < n; i++){
 
        nbr[i] = nbr[i-1];
        nbr[i] = nxt(p[i], nbr[i]);
    }
}
int main(){
 
    string s; cin >> s >> p;
    int ans = 0, lider = -1;
 
    kmp();
 
    for(int i = 0; i < s.size(); i++){
 
        lider = nxt(s[i], lider);
 
        if(lider == p.size()-1) ans++;
    }
 
    cout << ans;
 
    return 0;
}
