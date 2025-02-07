#include <bits/stdc++.h>
 
using namespace std;

// KMP computa online o nxt, importante para questões q usam
// a prefix function

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

// KMP Botelho e Dudu onde rola a pré computação
// para cada letra do alfabeto


template<class T>
struct KMP{
	int n; vi p; T in; vector<vi> a;
	template<class S>
	KMP(S s, T ain, int asz):n(sz(s)),p(n,0),in(ain),a(n+1,vi(asz,0)){
		rep(i, 1, n){
			int j = p[i-1];
			while(j and s[j]!=s[i])j = p[j-1];
			p[i] = j + (s[i]==s[j]);
			
		}
		rep(i, 0, n+1) rep(c, 0, asz){
				if (i and (i==n or c+in!=s[i]))a[i][c] = a[p[i-1]][c];
				else a[i][c] = i + (c+in == s[i]);
			}
	}
	int nxt(int cur, T c){return a[cur][c-in];}
};